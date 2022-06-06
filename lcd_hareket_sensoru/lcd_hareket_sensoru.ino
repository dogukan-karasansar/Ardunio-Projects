#include <LiquidCrystal_I2C.h>


#include <Wire.h>

#include <Servo.h>

Servo controlServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define hareketSensorPin 6
int hareket;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  pinMode(hareketSensorPin, INPUT);
  controlServo.attach(7);

}

void loop() {
  controlServo.write(0);
  delay(1000);
  controlServo.write(40);
  delay(1000);
  controlServo.write(120);
  hareket = digitalRead(hareketSensorPin);
  lcd.setCursor(0, 0);
  lcd.print("test");
  Serial.println(hareket);

  if (hareket == HIGH) {
    controlServo.write(0);
    delay(1000);
    controlServo.write(70);
    lcd.home();
    lcd.print("Kapı Kilitli");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Kapı Açık");
  }
}
