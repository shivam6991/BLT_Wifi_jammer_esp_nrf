<img width="1000" height="1000" alt="image" src="https://github.com/user-attachments/assets/49c8c600-2083-4315-b66d-c2857877621f" /># BLT_Wifi_jammer_esp_nrf
Bluetooth and wifi jammer - 2.4 GHz 
# ESP8266 BLE(Bluetooth) & Wi-Fi Jammer

This project aims to develop a jammer using ESP8266 and nrf24L01+ to interfere with BLE and Wi-Fi networks. The project utilizes the RF24 library to generate interference in the 2.4 GHz bands

## 📌 Requirements

- **NodeMCU ESP8266** (or a compatible ESP8266-based board)
- **NRF24L01+** module
- **Connecting wires**

## 🛠 Required Libraries

The following libraries must be installed in Arduino IDE ( these you will find in Library tab of Arduino IDE):

- [RF24](https://github.com/nRF24/RF24)
- [SPI](https://github.com/espressif/arduino-esp32/tree/master/libraries%2FSPI)

## ⚡ Hardware Connections

| ESP8266 Pin | NRF24L01+ Pin | Description |
|------------|---------------|-------------|
| D2 (GPIO4) | CSN            | Chip Select |
| D4 (GPIO2) | CE           | Module enable |
| D5 (GPIO14)| SCK           | Serial clock signal |
| D7 (GPIO13)| MOSI          | Data output |
| D6 (GPIO12)| MISO          | Data input |
| 3.3V       | VCC           | Power supply |
| GND        | GND           | Ground |


## 🚀 Setup & Execution

1. **Make the connections**: Complete the hardware setup as per the table above.
2. **Install libraries**: Use **Library Manager** in Arduino IDE to install the required libraries.
3. If you are using ESP8266 first time - you will need to install the ESP8266 board in **Board Manager**
4. The ESP8266 board manager URL is http://arduino.esp8266.com/stable/package_esp8266com_index.json
5. To use it, paste this URL into the "Additional Board Manager URLs" field in your Arduino IDE's preferences, then open the Boards Manager to search for and install the esp8266 package by the ESP8266 Community.
6. **USB-to-Serial Driver Issue**: Also, it can happen that the port might not be visible in the Arduino IDE when you will connect the board, the reason can be non-existence of CH340 driver - This is needed for ESP8266 (which needs serial communication) to talk with your PC via USB - the CH340 (USB-to-Serial) Chip is already present on the ESP8266 but the driver is sometimes not available by default in the OS you might be using. Also, in market, ESP8266 is present with two different types of USB-to-Serial chips (CH340 - by chinese manufacturer) and (CP2102-by silicon labs)The drivers are different for both kind of chips, so choose accordingly. Although CH340 is pretty common
check here how to find your USB-to-Serial chip type - https://share.google/images/IbjpL8XQ4jv4GmgwQ
Also if there is no name on your USB-to-serial IC it is also by a chinese manufacturer and it is CH340 chip 
   
8. CH340 Drivers for Windows, Mac and Linux - Gogo:Tronics
Gogo:Tronics - [https://sparks.gogo.co.nz › ch340](https://sparks.gogo.co.nz/ch340.html)
7. **Upload the code**: Open `jammer_esp_nrf.ino` in Arduino IDE and upload it to your ESP8266 board.
8. **Power up the device**: Connect your ESP8266 to a power source.

## 📡 Usage

When powered on, the device starts in **full Attack** mode
You can edit the code and install button and LED display to make it more interactive. I just made it with bare minimum HW and code. You will find better versions of this here - https://projecthub.arduino.cc/willy-js/esp8266-blebluetooth-wi-fi-jammer-53ca4b
https://github.com/EmenstaNougat/ESP32-BlueJammer/tree/main

**Note:** You can connect external power like small lipo batteries.

**Warning:** The nRF24l01 module getting extremely hot during use. This does not affect operation probably. But it may overheat your hand :D.
## 📜 License & Legal Disclaimer

This project is for **educational purposes only** and unauthorized usage is **illegal**. Please check your country's laws and adhere to ethical guidelines.
