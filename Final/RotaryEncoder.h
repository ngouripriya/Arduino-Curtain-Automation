#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H
#include <Arduino.h>


#define CLK 2
#define DT 3
#define SW 4



void RotaryEncoder_setup();
bool click();
int scroll();





#endif