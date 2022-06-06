const int BUTTON_PIN = 7;
const int GREEN_LED_PIN = 5;

int state = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(GREEN_LED_PIN, OUTPUT);
  Serial.begin(9600);



}

void loop() {
    state = digitalRead(BUTTON_PIN);
    if(state == LOW) {
       digitalWrite(GREEN_LED_PIN, HIGH);
       Serial.print(state);

    } else {
        digitalWrite(GREEN_LED_PIN, LOW);
         Serial.print(state);
   }
}
