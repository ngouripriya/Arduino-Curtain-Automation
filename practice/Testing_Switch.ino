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
int state =0;

void setup() {
        
	// Set encoder pins as inputs
	pinMode(CLK,INPUT);
	pinMode(DT,INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
	pinMode(SW, INPUT_PULLUP);

	// Setup Serial Monitor
	Serial.begin(9600);

	// Read the initial state of CLK
	lastStateCLK = digitalRead(CLK);
}

void loop() {
        
	// Read the current state of CLK
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
       

      }
      else if (state ==1){
        state =0;
        Serial.println("state= ");
        Serial.println(state);
        Serial.println("PLEASE");
    
      }
    }


		// Remember last button press event
		lastButtonPress = millis();




		// Remember last button press event

	}


	// Put in a slight delay to help debounce the reading
	delay(1);
}