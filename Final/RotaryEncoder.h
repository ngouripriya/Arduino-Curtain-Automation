#ifndef OPENCLOSECALC_H
#define OPENCLOSECALC_H
#define CLK 2
#define DT 3
#define SW 4

#include <Arduino.h>

void RotaryEncoder_setup();
bool click();
int scroll();


#endif