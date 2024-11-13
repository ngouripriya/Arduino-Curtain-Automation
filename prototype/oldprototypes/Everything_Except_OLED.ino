#define CLK 2
#define DT 3
#define SW 4
const int dirPin =8;
const int stepPin = 9;
const int stepsPerRevolution =200;

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;


#define indoor A5
#define outdoor A4
int state =0;
#define sleep 5

int preference = 200;
int currentIndoor;
int currentOutdoor;
int count = 0;


void setup() {
        
	// Set encoder pins as inputs
	pinMode(CLK,INPUT);
	pinMode(DT,INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
	pinMode(SW, INPUT_PULLUP);
  pinMode(indoor, INPUT);
  pinMode(outdoor, INPUT);
  currentIndoor = analogRead(indoor);
  currentOutdoor = analogRead(outdoor);


	// Setup Serial Monitor
	Serial.begin(9600);

	// Read the initial state of CLK
	lastStateCLK = digitalRead(CLK);
}

void loop() {
    int btnState = digitalRead(SW);


	// Remember last CLK state
	lastStateCLK = currentStateCLK;
  if (btnState == LOW ) {
    if(millis() - lastButtonPress > 50){
      if(state ==0){
        state =1;
        Serial.println("state= ");
        Serial.println(state);
        Serial.println("PLEASE LET THIS WORK");
        currentStateCLK = digitalRead(CLK);

      }
      else if (state ==1){
        state =0;
        Serial.println("state= ");
        Serial.println(state);
        Serial.println("PLEASE");
    
      }
    }
  }

  if(state ==0){
    currentStateCLK = digitalRead(CLK);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

		// If the DT state is different than the CLK state then
		// the encoder is rotating CCW so decrement
		if (digitalRead(DT) != currentStateCLK) {
			counter --;
			currentDir ="CCW";
      digitalWrite(dirPin, LOW);
      for(int x=0; x< 5; x++){
        digitalWrite(stepPin, HIGH);
		    delayMicroseconds(1000);
		    digitalWrite(stepPin, LOW);
		    delayMicroseconds(1000);
      }
		} else {
			// Encoder is rotating CW so increment
			counter ++;
			currentDir ="CW";
      digitalWrite(dirPin, HIGH);
      for(int x=0; x< 5; x++){
        digitalWrite(stepPin, HIGH);
		    delayMicroseconds(1000);
		    digitalWrite(stepPin, LOW);
		    delayMicroseconds(1000);
      }
      
      delay(1);



		}

		Serial.print("Direction: ");
		Serial.print(currentDir);
		Serial.print(" | Counter: ");
		Serial.println(counter);


	}

	// Remember last CLK state
	lastStateCLK = currentStateCLK;

	// Put in a slight delay to help debounce the reading
	delay(1);
  }
  if (state ==1){
    currentIndoor = analogRead(indoor);
    currentOutdoor = analogRead(outdoor);

    //too dark inside and brighter outside
    if (currentIndoor < preference - 20 && currentIndoor < currentOutdoor) {
      open();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    } else if (currentIndoor > preference + 20 && currentIndoor < currentOutdoor) {
      close();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    } else if (currentIndoor < preference - 20 && currentIndoor > currentOutdoor) {
      close();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    } else if (currentIndoor > preference + 20 && currentIndoor > currentOutdoor) {
      open();
      Serial.println("indoor:  ");
      Serial.println(currentIndoor);
      Serial.println("outdoor: ");
      Serial.println(currentOutdoor);
    }

  }


}
void open() {
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  //digitalWrite(sleep, HIGH); //turns off sleep mode
  delayMicroseconds(1000);
  digitalWrite(stepPin, LOW);
  count++;
  //digitalWrite(sleep, LOW);
}

void close() {
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  //digitalWrite(sleep, HIGH); //turns off sleep mode
  delayMicroseconds(1000);
  digitalWrite(stepPin, LOW);
  //digitalWrite(sleep, LOW);
  count--;
}

	
