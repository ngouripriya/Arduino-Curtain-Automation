// Define pin connections & motor's steps per revolution
//sources: 
//https://lastminuteengineers.com/a4988-stepper-motor-driver-arduino-tutorial/#:~:text=Wiring%20an%20A4988%20Stepper%20Motor%20Driver%20to%20an%20Arduino,-Now%20that%20we&text=The%20connections%20are%20straightforward.,%2C%201A%2C%20and%201B%20pins.
//https://www.makerguides.com/a4988-stepper-motor-driver-arduino-tutorial/
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200;


void setup()
{
	// Declare pins as Outputs
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
}
void loop()
{
	// Set motor direction clockwise
	digitalWrite(dirPin, HIGH);

	// Spin motor slowly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(2000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(2000);
	}
	delay(1000); // Wait a second
	
	// Set motor direction counterclockwise
	digitalWrite(dirPin, LOW);

	// Spin motor quickly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(1000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(1000);
	}
	delay(1000); // Wait a second
}

