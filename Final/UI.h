#ifndef UI_H
#define UI_H
#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
 
#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_ADDR 0x3C

const int SETUP = 0;
const int AUTOMATIC = 1;
const int MANUAL = 2;
//const int CLOCK = 3;


void UI_setup();
void updateScreen(int mode);
void switchToMode(int mode);
void modeSetup();
void modeAutomatic();
void modeManual();
void modeClock();
void printToScreen(String word);

#endif
//all code before this line so no duplicate declarations