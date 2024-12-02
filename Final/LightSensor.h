#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#define indoorPin A3
#define outdoorPin A2
#include <Arduino.h>

int indoor();
int outdoor();
int preference();
void setPreference();


#endif