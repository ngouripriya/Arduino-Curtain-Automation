#include "SetUp.h"
#include "UI.h"
#include "Motor.h"
#include "LightSensor.h"

void modeSetup(){
  printToScreen("Set max open");
  maxSetup();

  printToScreen("Set closed");
  minSetup();

  printToScreen("Set preference");
  prefSetup();

}

void maxSetup() {
  //let them open and close like in manual and setMax position when click occurs
}

void minSetup() {
  //same as maxSetup but setMin when click occurs
}

void prefSetup() {
  // same as other setups just setPreference when click occurs
}
