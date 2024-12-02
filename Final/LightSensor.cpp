#include "LightSensor.h"
#include "UI.h"
#include <Arduino.h>

//static int currentIndoor;
//static int currentOutdoor;
//static int count = 0;
static int pref = -1;

void lightSensor_setup(){
  pinMode(indoor, INPUT);
  pinMode(outdoor, INPUT);

}

int indoor() {
  return analogRead(indoorPin);
}

int outdoor() {
  return analogRead(outdoorPin);
}

int preference() {
  if (pref == -1) {
    return analogRead(indoorPin);
  } else {
    return pref;
  }
}
void setPreference() {
  pref = analogRead(indoorPin);
}