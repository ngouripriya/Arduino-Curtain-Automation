#ifndef MOTOR_H
#define MOTOR_H
const int dirPin = 8;
const int stepPin = 9;
const int stepsPerRevolution = 200;
#include <Arduino.h>

void motor_setup();
void manualTurn(int turn);
int getPos();
void updatePos(int update);
void setMax(int newMax);
void setMin(int newMin);
int getMax();
int getMin();


#endif