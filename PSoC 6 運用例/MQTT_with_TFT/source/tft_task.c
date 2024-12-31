/******************************************************************************
*
* File Name: tft_task.c
*
* Description: This file contains task and functions related to the tft_task
* that demonstrates controlling a TFT display using the EmWin Graphics Library
* and AppWizard GUI design tool.
* The project displays a start up screen with Infineon logo and
* text "INFINEON EMWIN GRAPHICS DEMO TFT DISPLAY".
*
* The project then displays the following screens in a loop
*
*   1. A screen showing text alignment, styles, and modes
*   2. A screen showing text colors
*   3. A screen showing normal fonts
*   4. A screen showing bold fonts
*   5. A screen showing color gradients
*   6. A screen showing 2D graphics with horizontal lines, vertical lines
*       arcs and filled rounded rectangle
*   7. A screen showing 2D graphics with concentric circles and ellipses
*   8. A screen showing colorful concentric circles
*   9. A screen showing a bitmap image
*
*******************************************************************************
* Copyright 2021-2023, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/
#include <string.h>

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "GUI.h"
#include "mtb_st7789v.h"
#include "tft_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/*******************************************************************************
* Macros
*******************************************************************************/
/*******************************************************************************
* Global Variables
*******************************************************************************/
extern GUI_CONST_STORAGE unsigned short QRcode_200[];
extern GUI_CONST_STORAGE unsigned short QRcode_100[];
extern GUI_CONST_STORAGE unsigned short home[];
extern GUI_CONST_STORAGE unsigned short i[];
extern GUI_CONST_STORAGE unsigned short monkey[];
extern GUI_CONST_STORAGE unsigned short chinese_bk_1[];
extern GUI_CONST_STORAGE unsigned short chinese_wt_1[];
extern GUI_CONST_STORAGE unsigned short red_circle_20[];
extern GUI_CONST_STORAGE unsigned short blue_circle_20[];
extern GUI_CONST_STORAGE unsigned short red_circle_40[];

extern char car_license[9];

extern char money[6];
extern char time_in[26];
extern char balance[10];

QueueHandle_t tft_page_q;
int tft_page_buf;

/* The pins are defined by the st7789v library. If the display is being used
 *  on different hardware the mappings will be different. */
const mtb_st7789v_pins_t tft_pins =
{
    .db08 = CYBSP_J2_2,
    .db09 = CYBSP_J2_4,
    .db10 = CYBSP_J2_6,
    .db11 = CYBSP_J2_10,
    .db12 = CYBSP_J2_12,
    .db13 = CYBSP_D7,
    .db14 = CYBSP_D8,
    .db15 = CYBSP_D9,
    .nrd  = CYBSP_D10,
    .nwr  = CYBSP_D11,
    .dc   = CYBSP_D12,
    .rst  = CYBSP_D13
};

// https://www.cnblogs.com/armfly/p/14923360.html
GUI_CONST_STORAGE GUI_BITMAP image_0 = {
  200, // xSize
  200, // ySize
  400, // BytesPerLine
  16, // BitsPerPixel
  (const unsigned char *) QRcode_200,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMP565
};

GUI_CONST_STORAGE GUI_BITMAP image_1 = {
  100, // xSize
  100, // ySize
  200, // BytesPerLine
  16, // BitsPerPixel
  (const unsigned char *) QRcode_100,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMP565
};

GUI_CONST_STORAGE GUI_BITMAP red_circle2 = {
  40, // xSize
  40, // ySize
  120, // BytesPerLine
  24, // BitsPerPixel
  (const unsigned char *) red_circle_40,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMPA565
};
GUI_CONST_STORAGE GUI_BITMAP red_circle = {
  30, // xSize
  30, // ySize
  90, // BytesPerLine
  24, // BitsPerPixel
  (const unsigned char *) red_circle_20,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMPA565
};
GUI_CONST_STORAGE GUI_BITMAP blue_circle = {
  30, // xSize
  30, // ySize
  90, // BytesPerLine
  24, // BitsPerPixel
  (const unsigned char *) blue_circle_20,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMPA565
};
GUI_CONST_STORAGE GUI_BITMAP image_home = {
  30, // xSize
  30, // ySize
  60, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *) home,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMP565
};
GUI_CONST_STORAGE GUI_BITMAP image_money = {
  30, // xSize
  30, // ySize
  60, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *) monkey,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMP565
};
GUI_CONST_STORAGE GUI_BITMAP image_i = {
  30, // xSize
  30, // ySize
  90, // BytesPerLine
  24, // BitsPerPixel
  (unsigned char *) i,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMPA565
};
GUI_CONST_STORAGE GUI_BITMAP chinese_bk1 = {
  73, // xSize
  13, // ySize
  219, // BytesPerLine
  24, // BitsPerPixel
  (const unsigned char *) chinese_bk_1,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMPA565
};
GUI_CONST_STORAGE GUI_BITMAP chinese_wt1 = {
  73, // xSize
  13, // ySize
  219, // BytesPerLine
  24, // BitsPerPixel
  (const unsigned char *) chinese_wt_1,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMPA565
};

/*******************************************************************************
* Function Prototypes
*******************************************************************************/


/*******************************************************************************
* Function Name: void tft_task(void *arg)
********************************************************************************
*
* Summary: The Following functions are performed in this task
*           1. Initializes the EmWin display engine
*           2. Displays startup screen for 3 seconds
*           3. In an infinite loop, displays the following screens on
               key press and release
*               a. Text alignment, styles and modes
*               b. Text color
*               c. Normal fonts
*               d. Bold fonts
*               e. Color bars
*               f. 2D graphics #1
*               g. 2D graphics #2
*               h. Concentric circles
*               i. Bitmap image
*
* Parameters:
*  arg: task argument (unused)
*
* Return:
*  None
*
*******************************************************************************/
void tft_task(void *arg)
{
//	int i;

    cy_rslt_t result;

    /* Initialize the display controller */
    result = mtb_st7789v_init8(&tft_pins);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    tft_page_q = xQueueCreate(10, sizeof(int));

    /* To avoid compiler warning */
    (void)result;

    /* Calling the AppWizard application entry point*/
    GUI_Init();
//    GUI_SetFont(&GUI_Font32_ASCII);
//    GUI_DispString("Hello world!");
    GUI_SetFont(&GUI_Font24_ASCII);
//    GUI_DispStringAt("connecting WIFI and MQTT now", 0, 100);
    GUI_DispStringAt("Initializing...", 100, 100);
    GUI_DrawBitmap(&chinese_wt1, 245, 225);
    vTaskSuspend(NULL);
    for(;;)
    {
    	if (pdPASS == xQueueReceive(tft_page_q, &tft_page_buf, portMAX_DELAY))
    	{
    		car_license[7] = '\0';

			if(tft_page_buf == 0)
			{
				GUI_SetBkColor(GUI_D_GREEN);
				GUI_Clear();
				GUI_SetColor(GUI_WHITE);
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("Please scan it to add LINE friend", 0, 10);
				GUI_DrawBitmap(&image_0, 94, 39);
				GUI_DrawBitmap(&chinese_wt1, 2, 225);
			}
			else if(tft_page_buf == 1 && strncmp(car_license, "\0\0\0\0\0\0\0", 7) != 0)
			{
				GUI_SetBkColor(GUI_SHELL);
				GUI_Clear();
				GUI_DrawBitmap(&chinese_bk1, 245, 2);
				GUI_SetColor(GUI_BLACK);
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("License plate:", 0, 25);
				GUI_SetFont(&GUI_Font32_ASCII);
				GUI_DispStringAt(car_license, 140, 24);
//				for (i=0; i<7; i++)
//				{
//					GUI_DispCharAt(car_license[i], (140+20*i), 23);
//				}
				GUI_SetFont(&GUI_Font20_ASCII);
				GUI_DispStringAt("Scan it to add LINE friend", 0, 100);
				GUI_DrawBitmap(&image_1, 210, 100);
//				GUI_SetFont(&GUI_Font20_ASCII);
				GUI_DrawBitmap(&blue_circle, 5, 205);
				GUI_DispStringAt(" :info.", 35, 210);
				GUI_DrawBitmap(&image_i, 85, 205);
				GUI_DrawBitmap(&red_circle, 160, 205);
				GUI_DispStringAt(" :check out", 190, 210);
				GUI_DrawBitmap(&image_money, 290, 205);
			}
			else if(tft_page_buf == 2 && strncmp(car_license, "\0\0\0\0\0\0\0", 7) != 0)
			{
				GUI_SetBkColor(GUI_SHELL);
				GUI_Clear();
				GUI_DrawBitmap(&chinese_bk1, 245, 2);
				GUI_SetColor(GUI_BLACK);
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("License plate:", 0, 25);
				GUI_SetFont(&GUI_Font32_ASCII);
				GUI_DispStringAt(car_license, 140, 23);
//				for (i=0; i<7; i++)
//				{
//					GUI_DispCharAt(car_license[i], (140+20*i), 23);
//				}
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("Entrance time:", 0, 70);
				GUI_DispStringAt(time_in, 0, 110);
//				for (i=0; i<strlen(time_in); i++)
//				{
//					GUI_DispCharAt(time_in[i], (0+15*i), 110);
//				}
				memset(time_in, '\0', strlen(time_in));
				GUI_DispStringAt("You currently need to pay $", 0, 150);
				GUI_DispStringAt(money, 260, 150);
//				for (i=0; i<strlen(money); i++)
//				{
//					GUI_DispCharAt(money[i], (260+15*i), 150);
//				}
				memset(money, '\0', strlen(money));
				GUI_SetFont(&GUI_Font20_ASCII);
				GUI_DrawBitmap(&blue_circle, 5, 205);
				GUI_DispStringAt(" :home", 35, 210);
				GUI_DrawBitmap(&image_home, 95, 205);
				GUI_DrawBitmap(&red_circle, 160, 205);
				GUI_DispStringAt(" :check out", 190, 210);
				GUI_DrawBitmap(&image_money, 290, 205);
			}
			else if(tft_page_buf == 3 && strncmp(car_license, "\0\0\0\0\0\0\0", 7) != 0)
			{
				GUI_SetBkColor(GUI_SHELL);
				GUI_Clear();
				GUI_DrawBitmap(&chinese_bk1, 245, 2);
				GUI_SetColor(GUI_BLACK);
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("License plate:", 0, 25);
				GUI_SetFont(&GUI_Font32_ASCII);
				GUI_DispStringAt(car_license, 140, 23);
//				for (i=0; i<7; i++)
//				{
//					GUI_DispCharAt(car_license[i], (140+20*i), 23);
//				}
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("You need to pay ", 0, 80);
				GUI_SetColor(GUI_DARKRED);
				GUI_DispStringAt("$", 160, 80);
				GUI_DispStringAt(money, 175, 80);
//				for (i=0; i<strlen(money); i++)
//				{
//					GUI_DispCharAt(money[i], (175+15*i), 80);
//				}
				memset(money, '\0', strlen(money));
				GUI_SetColor(GUI_DARKCYAN);
				GUI_DispStringAt("Please use RFID", 0, 130);
				GUI_SetColor(GUI_BLACK);
				GUI_SetFont(&GUI_Font20_ASCII);
				GUI_DrawBitmap(&blue_circle, 5, 205);
				GUI_DispStringAt(" :info.", 35, 210);
				GUI_DrawBitmap(&image_i, 85, 205);
				GUI_DrawBitmap(&red_circle, 160, 205);
				GUI_DispStringAt(" :home", 190, 210);
				GUI_DrawBitmap(&image_home, 250, 205);
			}
			else if(tft_page_buf == 5 && strncmp(car_license, "\0\0\0\0\0\0\0", 7) != 0)
			{
				GUI_SetBkColor(GUI_SHELL);
				GUI_Clear();
				GUI_DrawBitmap(&chinese_bk1, 245, 2);
				GUI_SetColor(GUI_BLACK);
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("License plate:", 0, 25);
				GUI_SetFont(&GUI_Font32_ASCII);
				GUI_DispStringAt(car_license, 140, 23);
//				for (i=0; i<7; i++)
//				{
//					GUI_DispCharAt(car_license[i], (140+20*i), 23);
//				}
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("Balance: ", 0, 80);
				if(balance[0] == '-') GUI_SetColor(GUI_DARKRED);
				else GUI_SetColor(GUI_DARKGREEN);
				GUI_DispStringAt("$", 85, 80);
				GUI_DispStringAt(balance, 100, 80);
//				for (i=0; i<strlen(balance); i++)
//				{
//					GUI_DispCharAt(balance[i], (100+15*i), 80);
//				}
				memset(balance, '\0', strlen(balance));
				GUI_SetColor(GUI_DARKRED);
				GUI_SetFont(&GUI_Font24B_ASCII);
				GUI_DispStringAt("Please leave within 5 minutes.", 0, 130);
//				GUI_SetFont(&GUI_Font20_ASCII);
//				GUI_SetColor(GUI_BLACK);
//				GUI_DispStringAt("Push 'SW2' to check out", 0, 180);
//				GUI_DispStringAt("Push 'SW4' to check the payment", 0, 210);
			}
			else if(tft_page_buf == 6 && strncmp(car_license, "\0\0\0\0\0\0\0", 7) != 0)
			{
				GUI_SetBkColor(GUI_SHELL);
				GUI_Clear();
				GUI_DrawBitmap(&chinese_bk1, 245, 2);
				GUI_SetColor(GUI_BLACK);
				GUI_SetFont(&GUI_Font24_ASCII);
				GUI_DispStringAt("License plate:", 0, 25);
				GUI_SetFont(&GUI_Font32_ASCII);
				GUI_DispStringAt(car_license, 140, 23);
//				for (i=0; i<7; i++)
//				{
//					GUI_DispCharAt(car_license[i], (140+20*i), 23);
//				}
				GUI_SetColor(GUI_DARKRED);
				GUI_SetFont(&GUI_Font32B_ASCII);
				GUI_DispStringAt("Please push ", 0, 100);
				GUI_DrawBitmap(&red_circle2, GUI_GetStringDistX("Please push "), 95);
				GUI_DispStringAt(" button", GUI_GetStringDistX("Please push ")+40, 100);
				GUI_SetColor(GUI_BLACK);
				GUI_SetFont(&GUI_Font20_ASCII);
				GUI_DrawBitmap(&blue_circle, 5, 205);
				GUI_DispStringAt(" :info.", 35, 210);
				GUI_DrawBitmap(&image_i, 85, 205);
				GUI_DrawBitmap(&red_circle, 160, 205);
				GUI_DispStringAt(" :check out", 190, 210);
				GUI_DrawBitmap(&image_money, 290, 205);
			}
    	}
//    	vTaskSuspend(NULL);
    }
}
/* END OF FILE */
