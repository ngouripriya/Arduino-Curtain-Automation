#include "Manual.h"
#include "UI.h"
#include "RotaryEncoder.h"
#include "Motor.h"
#include <string.h>



//turn the motor left and right with the encoder
//full open
//full close 


  void modeManual() {
  static int lastStateCLK = LOW;  
  static int counter = 0;    
  int currentStateCLK;     


  while (!click()) { 
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

		  Serial.print(" | Counter: ");
		  Serial.println(counter);


	  }

	lastStateCLK = currentStateCLK;

	delay(1);
    
}
  }
  
  
   
  


