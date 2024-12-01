#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#define indoor A5
#define outdoor A4
#include <Arduino.h>

int indoor();
int outdoor();
int preference();
void setPreference();


#endif