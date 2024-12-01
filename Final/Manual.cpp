#include "Manual.h"
#include "UI.h"
#include "RotaryEncoder.h"
#include "Motor.h"
#include <string.h>



//turn the motor left and right with the encoder
//full open
//full close 
// exit

static int scrolling =0;
//0 = manual override, 1 -> open, 2-> close, 3-> exit
//static int modes = 0;
static int lastStateCLK = LOW;  
static int counter = 0;    
static int currentStateCLK;  
int ManualMode = -1;
int ManualModeLast = -2;


void modeManual() {
   
  while(scrolling ==0){
    ManualOptionsDisplay();
  }


  while (scrolling == 1) { 
    if(ManualMode == MANUAL_OVERRIDE){
      ManualOverride(); 
    }
    if(ManualMode == OPEN){
      
    }
    if(ManualMode == CLOSE){
      
    }
    if(ManualMode == EXIT){
      ExitToMenu();
   
    }
  }


}




void ManualOptionsDisplay(){
  ManualMode = scroll();
  if(ManualMode != ManualModeLast){
    ChangeManualDisplay(ManualMode);
//    Serial.println(ManualMode);
    ManualModeLast = ManualMode;
  }

  if(click()){
    scrolling = 1;
  }
}


void ChangeManualDisplay(int mode){
  if(mode == MANUAL_OVERRIDE ){
    printToScreen("Override");
  }
  else if(mode == OPEN){
    printToScreen("Open");
  }

  else if(mode == CLOSE){
    printToScreen("Close");   
  }

  else if(mode == EXIT){
    printToScreen("Exit");    
  }

}


void ManualOverride(){
  currentStateCLK = digitalRead(CLK);

    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

      if (digitalRead(DT) != currentStateCLK) {
        counter ++;

        digitalWrite(dirPin, HIGH);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
        }
      } 
      else {
        digitalWrite(dirPin, LOW);
        for(int x=0; x< 10; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
        counter ++;        
        }        
        delay(1);

      }

//		  Serial.print(" | Counter: ");
//		  Serial.println(counter);


	  }

  if(click()){
    scrolling = 0;
  }
	lastStateCLK = currentStateCLK;

	delay(1);

}
  
  
void fullOpen(){

}

void fullClose(){

}

void ClickToExit(){


}

void ExitToMenu(){
  scrolling = 5;

}
   
  


