int buzzerPin = 7;
int nemOlcer = 8;
int veri;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(nemOlcer, INPUT);
  Serial.begin(9600);
}

void loop() {
  veri = digitalRead(nemOlcer);
  Serial.println(veri);
  if(!veri) {
    tone(buzzerPin, 140);
    digitalWrite(buzzerPin, HIGH);
  }
  
  else {
     noTone(buzzerPin);
     digitalWrite(buzzerPin, LOW);
  }
 

}
