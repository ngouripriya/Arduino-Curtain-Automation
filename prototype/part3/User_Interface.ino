//OLED STUFF
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);

//ROTARY ENCODER STUFF
#define CLK 2
#define DT 3
#define SW 4

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;
int state =0;

//for defining modes
int scrolling =0;
int lastmode = -1;
const int SETUP = 0;
const int AUTOMATIC = 1;
const int MANUAL = 2;
const int CLOCK = 3;


void setup()
{
  //OLED
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  display.println("Welcome");

  display.display();
  delay(1000);

  //ENCODER
         
	pinMode(CLK,INPUT);
	pinMode(DT,INPUT);
	pinMode(SW, INPUT_PULLUP);

	Serial.begin(9600);

	lastStateCLK = digitalRead(CLK); 


}

void loop(){
  //while in the scrolling mode (before mode is selected)
  if(scrolling ==0){
    if(click()){
      scrolling =1;
    }
  }

  if(scrolling ==1){   
    int mode = turn();
    
    if(mode != lastmode){
      changeScreen(mode);
      Serial.println(mode);
      lastmode = mode;
    }
    
    if(click()){
      scrolling = 2;
      Serial.println("Click");
      Action(mode);
    }
  }


	
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


void changeScreen(int mode){
  display.clearDisplay();

  display.setCursor(0, 0);
  if(mode == SETUP){
    display.println("Setup");
  }
  else if(mode == AUTOMATIC){
    display.println("Automatic");
  }
  else if(mode == MANUAL){
    display.println("Manual");   
  }
  else if(mode == CLOCK){
    display.println("Clock");    
  }
  display.display();
 



}


void Action(int mode){
  if (mode == SETUP){
    Setup();
  }
  else if (mode == AUTOMATIC){
    Automatic();
  }
  else if (mode == MANUAL){
    Manual();
  }
  else if (mode == CLOCK){
    Clock();
  }
}


void Setup(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("in Setup");
  display.display();

}




void Automatic(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("in Auto");
  display.display();

}





void Manual(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("in Man");
  display.display();

}




void Clock(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("in Clk");
  display.display();

}








