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
    if (currentIndoor < preference - 20 && currentIndoor < currentOutdoor) {
      open();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    } 
    else if (currentIndoor > preference + 20 && currentIndoor < currentOutdoor) {
      close();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    } 
    else if (currentIndoor < preference - 20 && currentIndoor > currentOutdoor) {
      close();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    } 
    else if (currentIndoor > preference + 20 && currentIndoor > currentOutdoor) {
      open();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    }
  }
}