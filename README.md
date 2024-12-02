# Arduino-Curtain-Automation
## Overview:
This program was created to control the opening and closing of blinds using an Arduino Uno, a Nema 17 stepper motor, two photoresistors, a rotary encoder, a A4988 motor driver, and an I2C display. The blinds can be opened automatically, according to light level preference, and manually, using a rotary encoder.

## Setup:
### Hardware
Connect the following devices to an Arduino Uno as described:
Photoresistors: Connect one side of the photo resistors to pins A4 (outdoor light detection) and A5 (indoor light detection) and the ____V pin of the Arduino. Connect the other sides of the phoresistors to ground using a 5.6 k&Omega.

I2C OLED Display: 

A4988: Set the current limit of the A4988 according to the datasheet specifications. Connect the SLP and RST pins. Connect the DIR and Step pins to pins D8 and D9 of the Arduino respectively. Connect VMOT to the 5V source of the Arduino and VDD to the ___V source of the Arduino. The GND pins should be connected to the GND pins of the Arduino.

Nema 17 Stepper Motor: The motor should be connected to the 1A, 1B, 2A, and 2B pins according to the datasheets. 

Rotary Encoder: Connect the CLK pin to D2 of the Arduino. Connect the DT pin to D3 of the Arduino. The GND pin can be connected to the Arduino ground, and the + pin can be connected to the ____V pin of the Arduino.

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
