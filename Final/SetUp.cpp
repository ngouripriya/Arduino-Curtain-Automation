#include "SetUp.h"
#include "UI.h"
#include "Motor.h"
#include "LightSensor.h"
#include "RotaryEncoder.h"


int modes = 0;
//0->maxSetup
static int lastStateCLK = LOW;  
static int counter = 0;    
static int currentStateCLK;  


void modeSetup(){
  modes =0;
  printToScreen("Set max open");
  delay(1000);
  while(modes ==0){
  maxSetup();

  }

  printToScreen("Set closed");
  while(modes == 1){
    minSetup();
  }

  printToScreen("Set preference");
  while(modes =2 ){
    prefSetup();
    if(click()){
      break;
    }
  }

}

void maxSetup() {
    currentStateCLK = digitalRead(CLK);
    int current = getPos();
  

    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){



      if (digitalRead(DT) != currentStateCLK) {
//        counter ++;
        //this is opening

        //only turns if it doesn't go past max position
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
      else {
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
        delay(10);

      }

	  }

  if(click()){
    setMax(current);
    modes = 1;
  }
	lastStateCLK = currentStateCLK;

	delay(1);


}




void minSetup() {
      currentStateCLK = digitalRead(CLK);
    int current = getPos();
  

    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){



      if (digitalRead(DT) != currentStateCLK) {
//        counter ++;
        //this is opening

        //only turns if it doesn't go past max position
        int max = getMax();
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
      else {
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
        delay(10);

      }

	  }

  if(click()){
    setMin(current);
    modes = 2;
  }
	lastStateCLK = currentStateCLK;

	delay(1);



}

void prefSetup() {
  setPreference();
  
}
