//motor sürücü
int AIB = 6 ;
int AIA = 5 ;
int BIB = 10 ;
int BIA = 11;

//komutlar
char komut;
String voiceKomut;
//ledler
int ledPin = 2;


//ultrasonik sensör
#define echoPin 7
#define trigPin 8
#define buzzerPin 9

int maximumRange = 50;
int minimumRange = 0;

//mikrofon
#define mikroPin 3
#define mikroA0 A0


void setup() {
 Serial.begin(9600);
 
 pinMode(AIB,OUTPUT);
 pinMode(AIA,OUTPUT);
 pinMode(BIA,OUTPUT);
 pinMode(BIB,OUTPUT);

 pinMode(mikroPin, INPUT);
 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzerPin, OUTPUT);
 
 pinMode(ledPin, OUTPUT);

}

void loop() {
  int olcum = mesafe(maximumRange, minimumRange);
  melodi(olcum*10);
  komut = Serial.read();
  
  //Serial.println(komut);
  
  

 if(olcum > 0 && olcum <= 40) { 
       geri();
  } else { 
     if(komut == 's') {
       digitalWrite(ledPin, LOW);
       dur();
       
     } else if(komut == 'f') {
      digitalWrite(ledPin, HIGH);
       ileri();
       
     } else if(komut == 'b') {
      digitalWrite(ledPin, HIGH);
        geri();
  
     } else if(komut == 'r') {
       digitalWrite(ledPin, HIGH);
       delay(50);
       digitalWrite(ledPin, LOW);
       delay(50);
       digitalWrite(ledPin, HIGH);
       
        sag();
        
     } else if(komut == 'l') {
       digitalWrite(ledPin, HIGH);
       delay(50);
       digitalWrite(ledPin, LOW);
       delay(50);
       digitalWrite(ledPin, HIGH);
        sol(); 
        
     } else {
      dur();
     } 
      
  }
}

void dur() {
  analogWrite(AIB,0);
  analogWrite(AIA,40);
  analogWrite(BIB,40);
  analogWrite(BIA,0);
}
void ileri() {
  analogWrite(AIB,0);
  analogWrite(AIA,250);
  analogWrite(BIB,250);
  analogWrite(BIA,0);
}

void geri() {
  analogWrite(AIB,250);
  analogWrite(AIA,0);
  analogWrite(BIB,0);
  analogWrite(BIA,250); 
}

 void sag() {
  analogWrite(AIB,250);
  analogWrite(AIA, 0);
  analogWrite(BIB, 250);
  analogWrite(BIA, 0);
 }

 void sol() {
  analogWrite(AIB,0);
  analogWrite(AIA, 250);
  analogWrite(BIB, 0);
  analogWrite(BIA, 250);
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
