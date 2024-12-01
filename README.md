# Arduino-Curtain-Automation
## Overview:

## Installation:

## Setup:
### Hardware
Connect the following devices to an Arduino Uno as described:
Photoresistors:
I2C OLED Display:
A4988 & Nema 17 Stepper Motor: set current limit accordingly
Rotary Encoder:

Connect the motor to blinds.
### Software
Ensure that all files in the Final folder are held within a folder titled "main". Using the Arduino IDE, compile the code and upload to the Arduino Uno.

## Use:
Upon uploading the code/powering the Arduino, the setup screen will be displayed.
1. Turn the rotary encoder until the blinds are open the maximum amount, and click the rotary encoder
2. Turn the rotary encoder until the blinds are completely closed, and click the rotary encoder
3. Turn the rotary encoder until the room has reached the prefered light level, and click the rotary encoder

The system should now be setup, with options to setup again, control the system manually (using the rotary encoder), and turn on automatic adjustment of the blinds. These options can be seen by turning the rotary encoder and selected by clicking the rotary encoder:
 - Setup: Repeat steps 1-3 for setup as described above. Once selected, the setup phase must be completed before returning to the main menu
 - Automatic: The blinds will adjust automatically to meet the preference set in the Setup. The blinds will not open/close past the maximum and minimum amounts set in Setup. Click the rotary encoder to exit this mode
 - Manual: Different manual options can be selected by scrolling and clicking with the rotary encoder. Clicking Open or Close will fully open/close the blinds. Clicking Override allows the user to open/close the blinds by turning the rotary encoder; to exit, click the rotary encoder. Clicking Exit will return to the main screen.  
