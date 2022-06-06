#define manyetik 7
#define lacivertLed 6
#define sariLed 5

void setup() {
  Serial.begin(9600);
  pinMode(manyetik, INPUT);
  pinMode(lacivertLed, OUTPUT);
  pinMode(sariLed, OUTPUT);

}

void loop() {
  int statusManyetik = digitalRead(manyetik);
  Serial.println(statusManyetik);
  if (statusManyetik) {
    digitalWrite(lacivertLed, HIGH);
    digitalWrite(sariLed, HIGH);

  } else {
    digitalWrite(lacivertLed, LOW);
    digitalWrite(sariLed, LOW);

  }
}
