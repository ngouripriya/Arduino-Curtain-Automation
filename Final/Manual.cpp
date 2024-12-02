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
  scrolling = 0;
  while(scrolling != 5){
   
    while(scrolling ==0){
      ManualOptionsDisplay();
    }


    while (scrolling == 1) { 
      if(ManualMode == MANUAL_OVERRIDE){
        ManualOverride(); 
        if(click()){
          ClickToExit();
        }
      }
      if(ManualMode == OPEN){
        fullOpen();
        scrolling = 0;      
      }

      if(ManualMode == CLOSE){
        fullClose();
        scrolling = 0;     
      }

      if(ManualMode == EXIT){
        ExitToMenu();
      }

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
      int max = getMax();
      int current = getPos();
      int min = getMin();
      Serial.print("Max = ");
      Serial.println(max);
      Serial.print("Min = ");
      Serial.println(min);
      Serial.print("Current = ");
      Serial.println(current);

      if (digitalRead(DT) != currentStateCLK) {
//        counter ++;
        //this is opening

        //only turns if it doesn't go past max position
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
        if(current - 10 >= min){
          digitalWrite(dirPin, LOW);
          for(int x=0; x< 10; x++){
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(1000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(1000);
 //         counter --;  

          }     
          current-=10;
          updatePos(-10);
          delay(10);
        }   
        delay(10);

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
  
  
//fullOpen is the Max in Motor
void fullOpen(){
  int maxPos = getMax();
  int currPos = getPos();
  Serial.print("Max = ");
  Serial.println(maxPos);
  Serial.print("Current = ");
  Serial.println(currPos);

  digitalWrite(dirPin, HIGH);
  for(int x=0; x< maxPos-currPos; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delay(30);
    
  }
  Serial.print("Updating = ");
  Serial.println(maxPos - currPos);
  updatePos(maxPos - currPos);
  

}

//closed is Min in Motor
void fullClose(){
  int minPos = getMin();
  int currPos = getPos();

  Serial.print("Min = ");
  Serial.println(minPos);
  Serial.print("Current = ");
  Serial.println(currPos);

  digitalWrite(dirPin, LOW);
  for(int x=0; x< currPos-minPos; x++){
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
    digitalWrite(stepPin, HIGH);
    delay(30);
  }
  Serial.print("Update = ");
  Serial.println(minPos-currPos);

  updatePos(minPos-currPos);
  //should hopefully be a negative number
  
}

void ClickToExit(){
  scrolling = 0;
}

void ExitToMenu(){
  scrolling = 5;
}
   
  


