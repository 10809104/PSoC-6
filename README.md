# PSoC 62S2-43012 運用例

該範例僅供參考

本專案展示了如何在 PSoC 62S2-43012 平台上使用 FreeRTOS 實現 UART 中斷、MQTT 客戶端和 TFT 顯示的任務。此範例適合對 PSoC 6 系列 MCU 和 FreeRTOS 有興趣的開發者參考學習。

## 功能特性

- **UART 中斷處理**：實現 UART 的中斷接收與發送功能，提高通信效率。
- **MQTT 客戶端**：透過 MQTT 協議與物聯網平台進行通信，實現消息的發布與訂閱。
- **TFT 顯示**：在 TFT 屏幕上顯示數據和信息，提供直觀的用戶界面。

## 硬體需求

- PSoC 62S2-43012 開發板
- TFT 顯示屏
- UART 模塊
- 無線網絡連接

## 軟體需求

- [ModusToolbox™](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/) 開發環境
- FreeRTOS 實時操作系統
- MQTT 客戶端庫

## 安裝與使用說明

1. **克隆專案**：使用以下命令將本倉庫克隆到本地：
   ```bash
   git clone https://github.com/10809104/PSoC-6.git
   ```

2. **導入專案**：在 ModusToolbox™ 中選擇 "Import Project" 功能，將克隆的專案導入。

3. **配置參數**：根據您的 Wi-Fi 和 MQTT 服務器信息，修改相應的配置文件，確保設備能正確連接。

4. **編譯與燒錄**：在開發環境中編譯專案，並將生成的固件燒錄到 PSoC 62S2-43012 開發板上。

5. **運行與測試**：重啟設備，觀察 TFT 顯示屏上的信息，並使用 MQTT 客戶端工具測試消息的發布與訂閱功能。

## MQTT 參數設置

如果要進行 Demo，MQTT 可設置為：
```c
#define MQTT_BROKER_ADDRESS               "test.mosquitto.org"
#define MQTT_PORT                         1883
#define MQTT_PUB_TOPIC                    "ledstatus"
#define MQTT_SUB_TOPIC                    "ledstatus"
```

## UART 設置

本專案的 UART 設置為：
- **Tx 引腳**：P0_2
- **Rx 引腳**：P0_3

### 多 UART 配置

本專案僅需配置一組 UART，以下是 GPIO 設置參考：

| UART  | Pin | MUC IO | EVK jumper pin |
|-------|----|--------|---------------|
| UART 0 | RX | P0[2] | J22.1 (IO0) |
| UART 0 | TX | P0[3] | J22.2 (IO1) |
| UART 1 | RX | P10[0] | J2.1 (A0) |
| UART 1 | TX | P10[1] | J2.2 (A1) |
| UART 2 | RX | P5[4] | J4.5 (D4) |
| UART 2 | TX | P5[5] | J4.6 (D5) |
| UART 3 | RX | P13[4] | J22.6 (IO5) |
| UART 3 | TX | P13[5] | J22.7 (IO6) |

## 調試注意事項

> **注意**：
> 本專案使用 **CM0+**，如果需要更改為其他處理器，請修改 `makefile` 配置。

## 注意事項

- **配置文件**：請確保正確配置 Wi-Fi 和 MQTT 的參數，包括 SSID、密碼、服務器地址和端口等。修改位置為 configs/wifi_config.h
- **MQTT 服務器**：確保 MQTT 服務器正常運行，並允許設備進行連接。修改位置為 configs/mqtt_client_config.h
- **代碼質量**：由於作者是新手，程式可能存在不完善之處，僅供參考學習。

## 參考資料

- [mtb-example-wifi-mqtt-client](https://github.com/Infineon/mtb-example-wifi-mqtt-client)
- [mtb-example-usb-device-quad-uart-bridge](https://github.com/Infineon/mtb-example-usb-device-quad-uart-bridge)
- [mtb-example-psoc6-emwin-tft-freertos](https://github.com/Infineon/mtb-example-psoc6-emwin-tft-freertos)

如需更多詳細信息，請參考上述鏈接中的相關範例和資料。

## 許可證

此專案包含以下兩種許可證：

### 1. MIT 許可證

你的代碼基於 **MIT 許可證** 開源，詳細許可條款請參見 [LICENSE](./LICENSE) 文件。

### 2. Cypress 軟體許可證

專案中使用了來自 **Cypress Semiconductor** 的軟體，這些軟體受 **Cypress 軟體許可證** 約束。Cypress的許可證條款詳情請參見 [Cypress EULA](https://github.com/10809104/PSoC-6/blob/master/PSoC%206%20%E9%81%8B%E7%94%A8%E4%BE%8B/MQTT_with_TFT/LICENSE)。

