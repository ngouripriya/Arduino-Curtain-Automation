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

  while (!click()) {
    int currentIndoor = indoor();
    int currentOutdoor = outdoor();
    int pref = preference();

    //too dark inside and brighter outside
    if (currentIndoor < pref - 20 && currentIndoor < currentOutdoor && getPos() > getMin()) {
      autoOpen();
    } 
    else if (currentIndoor > pref + 20 && currentIndoor < currentOutdoor) {
      autoClose();
    } 
    else if (currentIndoor < pref - 20 && currentIndoor > currentOutdoor && getPos() > getMin()) {
      autoClose();
    } 
    else if (currentIndoor > pref + 20 && currentIndoor > currentOutdoor) {
      autoOpen();
    }
  }
}

void autoOpen() {
  digitalWrite(dirPin, HIGH);

  if (!repeating(1)) {
    for(int x=0; x< 10 && getPos() <=  getMax() - 1; x++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
      updatePos(1);
    }
  }
  updatePast(1);
}

void autoClose() {
  digitalWrite(dirPin, LOW);

  if (!repeating(-1)) {
    for(int x=0; x< 10 && getPos() > getMin() - 1; x++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
      updatePos(1);
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