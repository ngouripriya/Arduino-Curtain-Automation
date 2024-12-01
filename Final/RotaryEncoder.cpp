#include "RotaryEncoder.h"
#include <string.h>

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;
int state =0;

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


int turn(){
	// Read the current state of CLK
	currentStateCLK = digitalRead(CLK);

	if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

		if (digitalRead(DT) != currentStateCLK) {
      if (counter != 3){
			  counter ++;
			  currentDir ="CCW";
      }
		} 
    else {
      if (counter != 0){
			  counter --;
			  currentDir ="CW";
      }
		}
    delay(10);
  }
  lastStateCLK = currentStateCLK;
   
  //added this cuz its being weird
  if (counter < 0){
    counter =0;
  }
  if (counter > 3){
    counter =3;
  }


  return counter;
}
