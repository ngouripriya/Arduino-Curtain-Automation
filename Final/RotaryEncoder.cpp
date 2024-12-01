#include "RotaryEncoder.h"
#include <string.h>

int scrollModes =0;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
////String currentDir ="";
unsigned long lastButtonPress = 0;



void RotaryEncoder_setup(){
  pinMode(CLK,INPUT);
	pinMode(DT,INPUT);
	pinMode(SW, INPUT_PULLUP);



	lastStateCLK = digitalRead(CLK); 

}

bool click(){
  int btnState = digitalRead(SW);
  bool clicked = false;
  
  if (btnState == LOW ) {
    if(millis() - lastButtonPress > 50){
      clicked = true;
    }
		lastButtonPress = millis();
	}
return clicked;
}


int scroll(){
	// Read the current state of CLK
	currentStateCLK = digitalRead(CLK);

	if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

		if (digitalRead(DT) != currentStateCLK) {
      if (scrollModes != 3){
			  scrollModes ++;
//			  currentDir ="CCW";
      }
		} 
    else {
      if (scrollModes != 0){
			  scrollModes --;
//			  currentDir ="CW";
      }
		}
    delay(10);
  }
  lastStateCLK = currentStateCLK;

  //added this cuz its being weird
  if (scrollModes < 0){
    scrollModes =0;
  }
  if (scrollModes > 3){
    scrollModes =3;
  }


  return scrollModes;
}

int turn(){

  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK){

    if (digitalRead(DT) != currentStateCLK) {
        counter ++;
    } 
    else {
        counter --; 
    }
    delay(10);
  }
  lastStateCLK = currentStateCLK;

    return counter;
}

