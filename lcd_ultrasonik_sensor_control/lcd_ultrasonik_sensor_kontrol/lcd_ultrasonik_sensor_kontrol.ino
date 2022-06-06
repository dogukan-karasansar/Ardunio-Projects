#include <LiquidCrystal.h>

#define echoPin 3
#define trigPin 4
#define buzzerPin 2

const int rs = 12, en = 11, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int minRange = 0, maxRange = 50;
int count = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
}

void(* resetFunc) (void) = 0;

void loop() {
  int olcum = mesafe(maxRange, minRange);
  if(count < 3) {
     lcd.setCursor(0, 0);
     lcd.print(olcum);
     lcd.print(" cm"); 
     melodi(olcum*10);
     lcd.clear();
  }
  
  if(olcum > 0) {
    delay(2000);
    count++;
    if(count >= 3) {
      lcd.setCursor(0, 2);
      lcd.print("Kapıda Biri Var");
    }
  } else {
     count = 0;
  }
}

int mesafe(int maxRange, int minRange) {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);

  if(distance >= maxRange || distance <= minRange) 
  return 0;
  return distance;
}

int melodi(int dly) {
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
