// Define pin connections & motor's steps per revolution
//https://lastminuteengineers.com/a4988-stepper-motor-driver-arduino-tutorial/#:~:text=Wiring%20an%20A4988%20Stepper%20Motor%20Driver%20to%20an%20Arduino,-Now%20that%20we&text=The%20connections%20are%20straightforward.,%2C%201A%2C%20and%201B%20pins.
#define indoor A5
#define outdoor A6
#define dirPin 2
#define stepPin 3
//#define steps 5
//#define reset D4
#define sleep 5

int preference = 200;
int currentIndoor;
int currentOutdoor;

void setup()
{
	// Declare pins as Outputs
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
  pinMode(indoor, INPUT);
  pinMode(outdoor, INPUT);
  currentIndoor = analogRead(indoor);
  currentOutdoor = analogRead(outdoor);
  //pinMode(reset, OUTPUT);
  //pinMode(sleep, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
	// Set motor direction clockwise
    currentIndoor = analogRead(indoor);
    currentOutdoor = analogRead(outdoor);

    //too dark inside and brighter outside
    if (currentIndoor < preference - 20 && currentIndoor < currentOutdoor) {
      open();
    } else if (currentIndoor > preference + 20 && currentIndoor < currentOutdoor) {
      close();
    } else if (currentIndoor < preference - 20 && currentIndoor > currentOutdoor) {
      close();
    } else if (currentIndoor > preference + 20 && currentIndoor > currentOutdoor) {
      open();
    }
}

void open() {
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  //digitalWrite(sleep, HIGH); //turns off sleep mode
  delayMicroseconds(10);
  digitalWrite(stepPin, LOW);
  //digitalWrite(sleep, LOW);
}

void close() {
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  //digitalWrite(sleep, HIGH); //turns off sleep mode
  delayMicroseconds(10);
  digitalWrite(stepPin, LOW);
  //digitalWrite(sleep, LOW);
}