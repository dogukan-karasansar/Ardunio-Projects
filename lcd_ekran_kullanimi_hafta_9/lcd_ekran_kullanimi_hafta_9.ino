#include <LiquidCrystal.h>


const int rs = 12 , en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define potansiyoPin A0
int potainsiyoValue = 0;


void setup() {
  Serial.begin(9600);
  pinMode(potansiyoPin, INPUT);
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("HELLO WORLD");
}

void loop() {
   
}
