#include "UI.h"
#include "Manual.h"
//#include "SetUp.h"
//#include "Automatic.h"
//#include "Clock.h"
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);


void UI_setup(){

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  display.println("Welcome");

  display.display();
  delay(200);
}


void updateScreen(int mode){
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

void switchToMode(int mode){
    if (mode == SETUP){
    modeSetup();
  }
  else if (mode == AUTOMATIC){
    modeAutomatic();
  }
  else if (mode == MANUAL){
    modeManual();
  }
  else if (mode == CLOCK){
    modeClock();
  }

}

void printToScreen(String word){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(word);
  display.display();
}

