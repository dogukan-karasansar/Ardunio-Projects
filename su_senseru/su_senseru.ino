#define sensorPin A0
#define greenPin 6
#define redPin 7
#define buzzerPin 5
void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int suSeviye = analogRead(sensorPin);
  Serial.println(suSeviye);
  delay(100);
  if (suSeviye > 200) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

}
