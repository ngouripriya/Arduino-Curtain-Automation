#include "SetUp.h"
#include "UI.h"
#include "Motor.h"
#include "LightSensor.h"
#include "RotaryEncoder.h"

static int scrolling =0;
//0 = manual override, 1 -> open, 2-> close, 3-> exit
static int modes = 0;
static int lastStateCLK = LOW;  
static int counter = 0;    
static int currentStateCLK;  
int ManualMode = -1;
int ManualModeLast = -2;

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
  currentStateCLK = digitalRead(CLK);
  int pos = 0;
  
  while (!click()) {
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
      if (digitalRead(DT) != currentStateCLK) {
        digitalWrite(dirPin, HIGH);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
          pos++;
          updatePos(1);
        }
      } else {
        digitalWrite(dirPin, LOW);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
          pos--;   
          updatePos(-1);   
        }        
      }
	  }
	  lastStateCLK = currentStateCLK;
	  delay(1);
  }

  setMax(pos);
}

void minSetup() {
  //same as maxSetup but setMin when click occurs
    //let them open and close like in manual and setMax position when click occurs
  currentStateCLK = digitalRead(CLK);
  int pos = 0;
  
  while (!click()) {
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
      if (digitalRead(DT) != currentStateCLK) {
        digitalWrite(dirPin, HIGH);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
          pos++;
          updatePos(1);
        }
      } else {
        digitalWrite(dirPin, LOW);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
          pos--;  
          updatePos(-1);    
        }        
      }
	  }
	  lastStateCLK = currentStateCLK;
	  delay(1);
  }

  setMin(pos);
}

void prefSetup() {
  // same as other setups just setPreference when click occurs
    //let them open and close like in manual and setMax position when click occurs
  currentStateCLK = digitalRead(CLK);
  int pos = 0;
  
  while (!click()) {
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
      if (digitalRead(DT) != currentStateCLK) {
        digitalWrite(dirPin, HIGH);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
          pos++;
          updatePos(1);
        }
      } else {
        digitalWrite(dirPin, LOW);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
          pos--; 
          updatePos(-1);     
        }        
      }
	  }
	  lastStateCLK = currentStateCLK;
	  delay(1);
  }
  setPreference();
}
