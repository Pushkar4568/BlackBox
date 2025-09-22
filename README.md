# BlackBox
STM32F401CCU6 blackbox project with serial logging using HAL API.



# STM32 Multi-Sensor "Black Box" Data Logger

This is a project to create a portable, multi-sensor data logger (a "black box") using an STM32F401CCU6 "Black Pill" board. It reads data from various analog and digital sensors and outputs the processed information via UART for real-time monitoring.

## Features
-   Reads **LPG concentration** in PPM from an MQ-2 gas sensor.
-   Reads **Carbon Monoxide (CO) concentration** in PPM from an MQ-7 gas sensor.
-   Reads **water level** as a percentage from a resistive water level sensor.
-   Reads **6-axis motion data** (3-axis accelerometer and 3-axis gyroscope) from an MPU-6050 IMU.
-   Processes all raw data into human-readable units (`PPM`, `%`, `g`, `°/s`).
-   Transmits all sensor data in a formatted string over UART.

## Hardware Required
* STM32F401CCU6 "Black Pill" Development Board
* ST-Link V2 Programmer
* MQ-2 Gas Sensor Module
* MQ-7 Gas Sensor Module
* Water Level Sensor Module
* MPU-6050 Gyroscope/Accelerometer Module
* Jumper Wires & Breadboard

## Software & Tools
* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
* STM32 HAL (Hardware Abstraction Layer) Libraries
* A serial terminal program (like PuTTY, Tera Term, or the Arduino IDE's Serial Monitor)

## Setup & Usage
1.  Clone this repository to your local machine.
2.  Connect all the hardware as shown in the wiring table below.
3.  Open the project in STM32CubeIDE.
4.  Build the project and flash the firmware to the STM32 board using an ST-Link.
5.  Power the board (e.g., via its USB port).
6.  Connect a USB-to-TTL serial adapter to `PA9` (TX) and `PA10` (RX) or use your preferred method to read the UART output.
7.  Open a serial terminal at **9600 baud** to view the sensor data stream.

## Wiring
| Sensor / Module | STM32F401 Pin |
| :-------------- | :------------ |
| MQ-2 (Analog Out) | `PA0` (ADC1_IN0) |
| MQ-7 (Analog Out) | `PA1` (ADC1_IN1) |
| Water Lvl (Analog Out)| `PA2` (ADC1_IN2) |
| MPU-6050 `SCL` | `PB6` (I2C1_SCL) |
| MPU-6050 `SDA` | `PB7` (I2C1_SDA) |
| UART `TX` for Output | `PA9` |

## Project Status
Currently in development. The next planned feature is to integrate an SD card module via SPI to log all data to a `.csv` file for persistent storage.
