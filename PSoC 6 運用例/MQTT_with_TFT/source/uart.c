/*
 * uart.c
 *
 *  Created on: 2024年7月5日
 *      Author: Administrator
 */
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"

#include "uart.h"
#include "publisher_task.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <string.h>

#define INT_PRIORITY    3
#define true  1
#define UART_DELAY      10u
#define TX_BUF_SIZE     100
#define RX_BUF_SIZE     1
#define BAUD_RATE       115200

#define plate_length	8

int paid = 0;

// Variable Declarations
cy_rslt_t    rslt;
uint8_t      tx_buf[TX_BUF_SIZE];
size_t       tx_length = TX_BUF_SIZE;

uint8_t      rx_buf[RX_BUF_SIZE];
size_t       rx_length = RX_BUF_SIZE;

// UART object and configuration structure
cyhal_uart_t uart_obj;
uint8_t read_data;

extern TaskHandle_t TFT_handle_t;
extern QueueHandle_t tft_page_q;
extern QueueHandle_t publisher_task_q;
QueueHandle_t uart_receive_task_q;

extern int tft_page_buf;

extern const int zero;
extern const int one;
extern const int six;

extern int can_push;

char uart_receive_buf;
char uart_receive[plate_length + 1];
char rfid[20];
char car_license[9];

const cyhal_uart_cfg_t uart_config =
{
	.data_bits = 8,
	.stop_bits = 1,
	.parity = INT_PRIORITY,
	.rx_buffer = rx_buf,
	.rx_buffer_size = RX_BUF_SIZE
};

// Event handler callback function
void uart_event_handler(void* handler_arg, cyhal_uart_event_t event)
{
    (void)handler_arg;
    if ((event & CYHAL_UART_IRQ_RX_DONE) == CYHAL_UART_IRQ_RX_DONE)
    {
    	int i = 0;

    	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    	// save receive
    	for (i=0; i<rx_length; i++)
    	{
    		xQueueSendToBackFromISR(uart_receive_task_q, &rx_buf[i], &xHigherPriorityTaskWoken);
    	}
    	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void uart_cyhal_initial_with_interrupt()
{
	cy_rslt_t  rslt;

    // Initialize the UART Block
	rslt = cyhal_uart_init(&uart_obj, P0_3, P0_2, NC, NC, NULL, &uart_config);
    CY_ASSERT(CY_RSLT_SUCCESS == rslt);

    // The UART callback handler registration
    cyhal_uart_register_callback(&uart_obj, uart_event_handler, NULL);

    // Enable required UART events
    cyhal_uart_enable_event(&uart_obj, (cyhal_uart_event_t)(CYHAL_UART_IRQ_RX_DONE), INT_PRIORITY, true);
}

void uart_receive_task(void *arg)
{
	int i = 0;

	publisher_data_t publisher_q_data;

    /* Initialize UART */
    uart_cyhal_initial_with_interrupt();

    uart_receive_task_q = xQueueCreate(50, sizeof(char));

	printf("\nUart HAL Interrupt\r\n");

    for (;;)
    {
    	cyhal_uart_read_async(&uart_obj, (void*)rx_buf, rx_length);
    	//cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_ON);
        //cyhal_system_delay_ms(250);
        //cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_OFF);
        //cyhal_system_delay_ms(250);
#if 0
    	cyhal_uart_getc(&uart_obj, &read_data, 0);
    	if(read_data == '0')
    	{
    		cyhal_gpio_write(CYBSP_LED_RGB_BLUE, CYBSP_LED_STATE_OFF);
    		printf("%c\r\n", read_data);
    	}
    	else if(read_data == '1')
    	{
    		cyhal_gpio_write(CYBSP_LED_RGB_BLUE, CYBSP_LED_STATE_ON);
    		printf("%c\r\n", read_data);
    	}
#endif
    	// 中斷觸發
    	if (pdPASS == xQueueReceive(uart_receive_task_q, &uart_receive_buf, portMAX_DELAY) && i != plate_length)
    	{
    		// 防掛機
    		if (i != 7 && uart_receive_buf == '!') {
    			printf("\n an error occur \r\n");
    			memset(uart_receive, '\0', strlen(uart_receive));
    			i=0;
    		}
    		else if (i != 7 && uart_receive_buf == '#'){
    			if (paid == 0){
					strcpy(uart_receive, car_license);

					if(uart_receive[plate_length-2] == '*')
						uart_receive[plate_length-1] = '7';
					else
						uart_receive[plate_length-1] = '4';

					/* Assign the publish command to be sent to the publisher task. */
					publisher_q_data.cmd = PUBLISH_MQTT_MSG;
					publisher_q_data.data = uart_receive;
					xQueueSend(publisher_task_q, &publisher_q_data, portMAX_DELAY);
				}
				else if (paid == 1) uart_receive[plate_length-1] = '6';

				// initial
				paid = 0;
				can_push = 0;
				memset(rfid, '\0', strlen(rfid));
				memset(car_license, '\0', strlen(car_license));
				memset(uart_receive, '\0', strlen(car_license));

				cyhal_gpio_write(CYBSP_LED_RGB_GREEN, CYBSP_LED_STATE_ON);
				cyhal_gpio_write(CYBSP_LED_RGB_RED, CYBSP_LED_STATE_OFF);
				xQueueSend(tft_page_q, &zero, portMAX_DELAY);
    		}
    		else{
    			uart_receive[i] = uart_receive_buf;
    			i++;
    		}
    	}

    	// 接收完成無遺漏
    	if (i == plate_length)
    	{
    		i=0;
    		if(uart_receive[plate_length-1] == '!')
    		{
        		if(uart_receive[plate_length-2] == '*') uart_receive[plate_length-1] = 0;
        		else
        		{
        			can_push = 1;
        			uart_receive[plate_length-1] = '0';
        		}
    			/* Assign the publish command to be sent to the publisher task. */
				publisher_q_data.cmd = PUBLISH_MQTT_MSG;
				publisher_q_data.data = uart_receive;
				xQueueSend(publisher_task_q, &publisher_q_data, portMAX_DELAY);

    			strcpy(car_license, uart_receive);
    			cyhal_gpio_write(CYBSP_LED_RGB_GREEN, CYBSP_LED_STATE_OFF);
				cyhal_gpio_write(CYBSP_LED_RGB_RED, CYBSP_LED_STATE_ON);
				xQueueSend(tft_page_q, &one, portMAX_DELAY);
//				if (TFT_handle_t != NULL) vTaskResume(TFT_handle_t);
    		}
    		else if(uart_receive[plate_length-1] == '#')
			{
    			if (paid == 0)
    			{
        			strcpy(uart_receive, car_license);
            		if(uart_receive[plate_length-2] == '*')
            			uart_receive[plate_length-1] = '7';
            		else
            			uart_receive[plate_length-1] = '4';
					/* Assign the publish command to be sent to the publisher task. */
					publisher_q_data.cmd = PUBLISH_MQTT_MSG;
					publisher_q_data.data = uart_receive;
					xQueueSend(publisher_task_q, &publisher_q_data, portMAX_DELAY);
    			}
    			else if (paid == 1)uart_receive[plate_length-1] = '6';

    			// initial
    			paid = 0;
    			can_push = 0;
    			memset(rfid, '\0', strlen(rfid));
    			memset(car_license, '\0', strlen(car_license));
    			memset(uart_receive, '\0', strlen(car_license));

				cyhal_gpio_write(CYBSP_LED_RGB_GREEN, CYBSP_LED_STATE_ON);
				cyhal_gpio_write(CYBSP_LED_RGB_RED, CYBSP_LED_STATE_OFF);
				xQueueSend(tft_page_q, &zero, portMAX_DELAY);
//				if (TFT_handle_t != NULL) vTaskResume(TFT_handle_t);
			}
    		else
    		{
    			if (tft_page_buf == 3 && can_push == 1)
    			{
        			paid = 1;
        			can_push = 0;

        			strcpy(rfid, uart_receive);
        			strcat(rfid, car_license);
        			rfid[15] = '3';
        			publisher_q_data.cmd = PUBLISH_MQTT_MSG;
    				publisher_q_data.data = rfid;
    				xQueueSend(publisher_task_q, &publisher_q_data, portMAX_DELAY);
    				car_license[7] = '1';
        			publisher_q_data.cmd = PUBLISH_MQTT_MSG;
    				publisher_q_data.data = car_license;
    				xQueueSend(publisher_task_q, &publisher_q_data, portMAX_DELAY);
    			}
    			else if(can_push == 1)
    			{
    				xQueueSend(tft_page_q, &six, portMAX_DELAY);
//    				if (TFT_handle_t != NULL) vTaskResume(TFT_handle_t);
    			}
    		}
			printf("\r\nGet input string\r\n");
			printf("uart_receive: %s\r\n", uart_receive);
			printf("car_license: %s\r\n", car_license);
			printf("rfid: %s\r\n", rfid);
    	}
    }
}

/* [] END OF FILE */


