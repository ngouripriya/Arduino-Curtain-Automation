g#define lightSensor D13

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lightLevel = digitalRead(lightSensor);
  Serial.println(lightLevel);
  delay(1000);

}
