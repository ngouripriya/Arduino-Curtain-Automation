#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#define indoorPin A1
#define outdoorPin A2
#include <Arduino.h>

void lightSensor_setup();
int indoor();
int outdoor();
int preference();
void setPreference();



#endif