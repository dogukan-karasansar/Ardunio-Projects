#include <Servo.h>

Servo dknServo;
//#define positionXPin A0
#define positionYPin A1
//#define sw 6

void setup() {
  Serial.begin(9600);
  //pinMode(positionXPin, INPUT);
  pinMode(positionYPin, INPUT);
  //pinMode(sw, INPUT);
  dknServo.attach(7);
  dknServo.write(0);
}

void loop() {
  int positionY = analogRead(positionYPin);
  int derece = map(positionY, 0, 1023, 0, 180);
  Serial.println(derece);
  dknServo.write(derece);

}
