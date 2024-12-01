#include "Automatic.h"
#include "LightSensor.h"
#include "UI.h"

static int scrolling =0;
static int modes = 0;
static int past[5] = {0, 0, 0, 0, 0};
int AutoMode = -1;
int AutoModeLast = -2;


void modeAutomatic(){
  printToScreen("Exit");

  while (!click()) {
    currentIndoor = indoor();
    currentOutdoor = outdoor();
    preference = preference();

    //too dark inside and brighter outside
    if (currentIndoor < preference - 20 && currentIndoor < currentOutdoor && getPos() > getMin()) {
      autoOpen();
    } 
    else if (currentIndoor > preference + 20 && currentIndoor < currentOutdoor) {
      autoClose();
    } 
    else if (currentIndoor < preference - 20 && currentIndoor > currentOutdoor && getPos() > getMin()) {
      autoClose();
    } 
    else if (currentIndoor > preference + 20 && currentIndoor > currentOutdoor) {
      autoOpen();
    }
  }
}

void autoOpen() {
  digitalWrite(dirPin, HIGH);
  for(int x=0; x< 10 && getPos() <=  getMax() - 1; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
    updatePos(1);
  }
}

void autoClose(
  digitalWrite(dirPin, LOW);
  for(int x=0; x< 10 && getPos() > getMin() - 1; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
    updatePos(1);
  }
)