#include "Motor.h"
#include "UI.h"

static int pos = 0;
static int Max = 200;
//most open
static int Min = 0;
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
  Serial.print("Pos = ");
  Serial.println(pos);

}

void setMax(int newMax){
  Max =  newMax;
  Serial.print("Max = ");
  Serial.println(newMax);
}

void setMin(int newMin){
  Min =  newMin;
  Serial.print("Min = ");
  Serial.println(newMin);
}


int getMax(){
  return Max;
}


int getMin(){
  return Min;
}





