#ifndef MOTOR_H
#define MOTOR_H
#define dirPin 8
#define stepPin  9
#define stepsPerRevolution 200
#include <Arduino.h>

void motor_setup();
void manualTurn(int turn);
int getPos();
void updatePos(int update);
int getMax();
int getMin();


#endif