#include "Motor.h"
#include "UI.h"

static int pos = 0;
static int Max =-5000;
static int Min = -5000;
//random values so it updates

void motor_setup(){
  pinMode(stepPin, OUTPUT); 
  pinMode(dirPin, OUTPUT);

}

int getPos(){
  return pos;

}

void updatePos(int update){
  pos += update;

}

int getMax(){
  return Max;
}

int getMin(){
  return Min;
}





