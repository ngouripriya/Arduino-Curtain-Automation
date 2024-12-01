#include "UI.h"
#include "RotaryEncoder.h"


int scrolling = 0;
int lastmode = -1; //random invalid mode so it updates on the first iteration
int mode = -10;
 

void setup(){
  //OLED
  UI_setup();

  //Rotary Encoder
  RotaryEncoder_setup();


  Serial.begin(9600);

}


void loop(){
  if(scrolling == 0){
    if(click()){
      scrolling =1;
    }
  }

  if(scrolling ==1){   
    mode = turn();
    
    if(mode != lastmode){
      updateScreen(mode);
      Serial.println(mode);
      lastmode = mode;
    }
    
    if(click()){
      scrolling = 2;
      Serial.println("Click");
      switchToMode(mode);
    }
  }

}
