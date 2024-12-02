#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#define indoorPin A5
#define outdoorPin A4
#include <Arduino.h>

int indoor();
int outdoor();
int preference();
void setPreference();


#endif