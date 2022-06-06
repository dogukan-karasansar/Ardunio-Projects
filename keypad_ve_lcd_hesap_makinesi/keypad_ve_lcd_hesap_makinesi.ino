
#include <LiquidCrystal.h>
#include <Keypad.h>

//lcd port
const int /*rs = 7, en = 6,*/ d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(A0, A1, d4, d5, d6, d7);

//keyboard
const byte ROWS = 4;
const byte COLUMN = 4;
char key;
boolean final = false;
boolean presentValue = false;
String num1, num2;
char keys [ROWS] [COLUMN] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', 'C'},
  {'*', '0', '/', '='}  
};

byte rowpins[ROWS] = {9, 8, 7, 6};
byte colpins[COLUMN] = {5, 4, 3, 2};
char op;
float answer = 0;

Keypad islem_pad = Keypad(makeKeymap(keys), rowpins, colpins, ROWS, COLUMN);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
 key = islem_pad.getKey();

   if(key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8'  || key == '9' || key == '0')) {
  
   if(presentValue != true) {
    num1 = num1 + key;
    int numLength = num1.length();
    lcd.setCursor(0, 0);
    lcd.print(num1);
   } else {
    num2 = num2 + key;
    int numlength2 = num2.length();
    int numLength = num1.length();
    lcd.setCursor(1 + numLength, 0);
    lcd.print(num2);
    final = true;
   }

 } else if(presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+')) {
  
     lcd.setCursor(num1.length(), 0);
     presentValue = true;
     op = key;
     lcd.print(op);
     
 } else if(final == true && key != NO_KEY & key == '=') {
  
     if(op == '+') {
        answer = num1.toInt() + num2.toInt();
     } else if(op == '-') {
      
        answer = num1.toInt() - num2.toInt();
      
     } else if(op == '*') {
        answer = num1.toInt() * num2.toInt();
     } else if(op == '/') {
        answer = num2.toFloat() / num1.toFloat();
     }
     
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("= ");
     lcd.print(answer);
     
 } else if(key != NO_KEY && key == 'C') {
  lcd.clear();
  final = false;
  presentValue = false;
  num1 = "";
  num2 = "";
  op = ' ';
  answer = 0;
 }
}
