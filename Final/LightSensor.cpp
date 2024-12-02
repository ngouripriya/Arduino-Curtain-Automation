#include "LightSensor.h"
#include "UI.h"
#include <Arduino.h>

static int pref = -1;

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