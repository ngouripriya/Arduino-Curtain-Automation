#include "Motor.h"
#include "UI.h"

static int pos = 0;
static int Max =-5000;
//most open
static int Min = -5000;
//most closed

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

void setMax(int newMax){
  Max =  newMax;
}

void setMin(int newMin){
  Min =  newMin;
}


int getMax(){
  return Max;
}


int getMin(){
  return Min;
}





