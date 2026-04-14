# LED Matrix Display - System architechture

## 1) Overview
- The LED Matrix I am building would have many modes and the user be able to interact with them using the button provided. The Matrix Display would have a real time Clock and Scrolling Text and will be able to animations.

## 2) Components
- 1. ESP32 Dev Board
  - ESP32 Dev Board is the main processing part for my project.
  - It is essential and would be control and interacting with nearly all components.
  - It is essential for the framebuffering data for the led matrix.

- 2. HUB75 LED MATRIX 32x64
  - It is also very part of the project.
  - Its multeplexed system scans whole led rows coloumns.
  - It must be updated or refreshed continuously for stable image display.
 
- 3. Power Supply System ( Custom PCB included )
  - The system would be using a dedicated power supply system for stable 5v supply
  - The power supply would have a custom PCB for the project that would ensure stable current flow to all the component, like the HUB75 LED Matrix, ESP32 and the RTC.
 
- 4. RTC module
  - Its a real time clock module that would communicate with the ESP32 through a I2C protocol
  - It would be essential for the Clock mode of our led matrix Display

- 5. Buttons
  - This would a button input system that would allow the user to interact with the display
  - They would be useful for the the changing modes, brightness,etc.

## 3) The System Block Diagram

<img width="721" height="531" alt="System-Architecture" src="https://github.com/user-attachments/assets/9b016eef-1351-47aa-aaca-aa729e80d1fb" />

This is simple represtation of the data flow and power flow for the project.

## 4) Power flow and Data flow Overview
The data flow would be as follow:
- The ESP32 would be main controlling unit aka the brain of the project
- The INPUT from the user would be given by the buttons to the ESP32.
- The INPUT for the clock would be give by the RTC module to ESP32.
- The ESP32 would then use this data and control the LED MATRIX HUB75 and display the OUTPUT.

The power control for the project would be:
- The custom power distribution supply would be used to ensure stable current and voltage is distributed to all major components like the ESP32, HUB75 Led matrix and the RTC module.
- The PCB would supply sufficient current to the LED matrix.
