int AIB = 6 ;
int AIA = 5 ;
int BIB = 10 ;
int BIA = 11;

#define echoPin 7
#define trigPin 8
#define buzzerPin 9

int maximumRange = 50;
int minimumRange = 0;



void setup() {
Serial.begin(9600);

 pinMode(AIB,OUTPUT);
 pinMode(AIA,OUTPUT);
 pinMode(BIA,OUTPUT);
 pinMode(BIB,OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzerPin, OUTPUT);

}

void loop() {
  int olcum = mesafe(maximumRange, minimumRange);
  melodi(olcum*10);
  char komut = Serial.read();
  Serial.println(komut);

 if(olcum > 0 && olcum <= 40) {
   analogWrite(AIB,0);
   analogWrite(AIA,40);
   analogWrite(BIB,40);
   analogWrite(BIA,0); 
  } else {
     if(komut == 'S') {
       analogWrite(AIB,0);
       analogWrite(AIA,40);
       analogWrite(BIB,40);
       analogWrite(BIA,0);
     } else if(komut == 'F') {
       analogWrite(AIB,0);
       analogWrite(AIA,255);
       analogWrite(BIB,255);
       analogWrite(BIA,0); 
     } else if(komut == 'B') {
       analogWrite(AIB,255);
       analogWrite(AIA,0);
       analogWrite(BIB,0);
       analogWrite(BIA,255); 
     } 
      
  }
}


int mesafe(int maximumRange, int minimumRange) { 
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);
  if(distance >= maximumRange || distance <= minimumRange)
  return 0;
  return distance;
 }


 int melodi(int dly) {
    tone(buzzerPin, 452);
    delay(dly);
    noTone(buzzerPin);
    delay(dly);
}
