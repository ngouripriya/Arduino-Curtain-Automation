#define lightSensor A5

#connect to the positive set

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lightLevel = analogRead(lightSensor);
  Serial.println(lightLevel);
  delay(1000);

}
