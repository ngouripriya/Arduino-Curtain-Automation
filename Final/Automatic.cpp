#include "Automatic.h"
#include "LightSensor.h"
#include "UI.h"
#include "Motor.h"
#include "RotaryEncoder.h"

static int scrolling =0;
static int modes = 0;
static int past[5] = {0, 0, 0, 0, 0};
int AutoMode = -1;
int AutoModeLast = -2;


void modeAutomatic(){
  printToScreen("Exit");
  delay(30);
  scrolling =0;

  while (scrolling ==0) {
    delay(50);
    int currentIndoor = indoor();
    int currentOutdoor = outdoor();
    int pref = preference();
/*    Serial.print("current = ");
    Serial.println(currentIndoor);
    Serial.print("Outdoor = ");
    Serial.println(currentOutdoor);
    Serial.print("pref = ");
    Serial.println(pref);
    */

    //too dark inside and brighter outside
    if (currentIndoor < pref - 20 && currentIndoor < currentOutdoor && getPos() > getMin()) {
      Serial.println("In 1");
      autoOpen();
    } 
    else if (currentIndoor > pref + 20 && currentIndoor < currentOutdoor) {
      Serial.println("In 2");
      autoClose();
    } 
    else if (currentIndoor < pref - 20 && currentIndoor > currentOutdoor && getPos() > getMin()) {
      Serial.println("In 3");
      autoClose();
    } 
    else if (currentIndoor > pref + 20 && currentIndoor > currentOutdoor) {
      Serial.println("In 3");
      autoOpen();
    }
    else{
      updatePast(0);
    }
    delay(30);
    if(click()){
      Serial.println("hello");

      scrolling = 5;
      //invalid, should exit
    }

    delay(50);
  }

}

void autoOpen() {
  int current = getPos();
  int max = getMax();
  int currPos = getPos();

  if (!repeating(1)) {
      if(current+10 <= max){
        digitalWrite(dirPin, HIGH);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
        }
        current = current+10;
        updatePos(10);
        delay(10);
      }

  }
  updatePast(1);
}

void autoClose() {
  int min = getMin();
  int current = getPos();
  if (!repeating(1)) {
    digitalWrite(dirPin, LOW);  
    if(current - 10 >= min){
      digitalWrite(dirPin, LOW);
      for(int x=0; x< 10; x++){
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);

      }     
      current-=10;
      updatePos(-10);
      delay(10);
    }  
  }    
  updatePast(-1);
}

bool repeating(int i) {
  if (i == -1 && past[0] == 1 && past[1] == -1 && past[2] == 1 && past[3] == -1 && past[4] == 1) {
    return true;
  } else if (i == 1 && past[0] == -1 && past[1] == 1 && past[2] == -1 && past[3] == 1 && past[4] == -1) {
    return true;
  } 
  else return false;
}

void updatePast(int i) {
  past[4] = past[3];
  past[3] = past[2];
  past[2] = past[1];
  past[1] = past[0];
  past[0] = i;
}