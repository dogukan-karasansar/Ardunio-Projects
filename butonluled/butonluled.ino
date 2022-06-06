const int BUTTON_PIN = 7;
const int RED_LED_PIN = 6;
const int GREEN_LED_PIN = 5;
const int WHITE_LED_PIN = 4; 
int state = 0;

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(WHITE_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  state = digitalRead(BUTTON_PIN);
  if(state == LOW) {
    digitalWrite(RED_LED_PIN, HIGH);
    delay(10000);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(10000);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(WHITE_LED_PIN, HIGH);
    delay(10000);
    
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(WHITE_LED_PIN, LOW);
   }
}
