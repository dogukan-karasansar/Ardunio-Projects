#define ldr A0
#define led 3
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light_parameter = analogRead(ldr);
  Serial.println(light_parameter);
  if(light_parameter < 400) {
    digitalWrite(led, HIGH);
  } else {
     digitalWrite(led, LOW);
  }
}
