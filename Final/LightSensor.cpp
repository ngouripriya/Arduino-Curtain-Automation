#include "LightSensor.h"
#include "UI.h"

static int preference = -1;

int indoor() {
  return analogRead(indoor);
}

int outdoor() {
  return analogRead(outdoor);
}

int preference() {
  if (preference == -1) {
    return analogRead(indoor);
  } else {
    return preference;
  }
}
void setPreference() {
  preference = analogRead(indoor);
}