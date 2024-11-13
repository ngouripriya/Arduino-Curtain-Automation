#define CLK 2
#define DT 3
#define SW 4
#define indoor A5
#define outdoor A4
#define dirPin 8
#define stepPin 9
#define sleep 5
#define stepsPerRevolution = 200
#define MANUAL = 0
#define LIGHT = 1

//photoresistors
int preference = 200;
int currentIndoor;
int currentOutdoor;
int repeatCounter = 0;
//rotary encoder
int counter = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0; //why unsigned long?
int state = 0;
String currentDir = "";



void setup() {
  //set up rotary encder
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  //motor
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  //photoresistors
  pinMode(indoor, INPUT);
  pinMode(outdoor, INPUT);

  Serial.begin(9600);
  lastStateCLK = digitalRead(CLK);
  currentIndoor = analogRead(indoor);
  currentOutdoor = analogRead(outdoor);
}

void loop() {
  //Read current CLK
  currentStateCLK = digitalRead(CLK);
  int btnState = digitalRead(SW);
  lastStateCLK = currentStateCLK;
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      if (state == MANUAL) {
        state = AUTOMATIC;
        Serial.println("state = AUTOMATIC");
      } else if (state == AUTOMATIC) {
        state = MANUAL;
        Serial.println("state = MANUAL");
      }
    }
  }
  lastButtonPress = millis();
  delay(1);
  
  if (state == MANUAL) {
    manualTurn();
  } else if (state == LIGHT) {
    automaticTurn();
  }
}

void turn() {
  for (int x = 0; x < 5; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
}

void manualTurn() {
  // If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    //check if rotating CCW
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      currentState = "CCW";
      digitalWrite(dirPin, LOW);
      turn();
    } else { //rotating CW
      counter++;
      currentDir = "CW";
      digitalWrite(dirPin, HIGH);
      turn();
    }
  }
}

void automaticTurn() {
  	// Set motor direction clockwise
  currentIndoor = analogRead(indoor);
  currentOutdoor = analogRead(outdoor);

    //too dark inside and brighter outside
  if (currentIndoor < preference - 20 && currentIndoor < currentOutdoor) {
    turnCW();
    Serial.println("indoor:  ");
    Serial.println(currentIndoor);
    Serial.println("outdoor: ");
    Serial.println(currentOutdoor);
  } else if (currentIndoor > preference + 20 && currentIndoor < currentOutdoor) {
    turnCCW();
    Serial.println("indoor:  ");
    Serial.println(currentIndoor);
    Serial.println("outdoor: ");
    Serial.println(currentOutdoor);
  } else if (currentIndoor < preference - 20 && currentIndoor > currentOutdoor) {
    turnCCW();
    Serial.println("indoor:  ");
    Serial.println(currentIndoor);
    Serial.println("outdoor: ");
    Serial.println(currentOutdoor);
  } else if (currentIndoor > preference + 20 && currentIndoor > currentOutdoor) {
    turnCW();
    Serial.println("indoor:  ");
    Serial.println(currentIndoor);
    Serial.println("outdoor: ");
    Serial.println(currentOutdoor);
  }
}

