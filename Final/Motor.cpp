#include "Motor.h"
#include "UI.h"
int modes = 0 ;

void motor_setup(){
  pinMode(stepPin, OUTPUT); 
  pinMode(dirPin, OUTPUT);

}



void manualTurn(int turn){   
    if(turn > 0){
      digitalWrite(dirPin, LOW);
      for(int x=0; x< 10; x++){
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }
    }

    else if(turn <0){
      digitalWrite(dirPin, HIGH);
      for(int x=0; x< 10; x++){
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }
    
    }
}

