int AIB = 6 ;
int AIA = 5 ;
int BIB = 10 ;
int BIA = 11 ;
void setup() {
 pinMode(AIB,OUTPUT);
 pinMode(AIA,OUTPUT);
 pinMode(BIA,OUTPUT);
 pinMode(BIB,OUTPUT);

}

void loop() {
  analogWrite(AIB,0);
  analogWrite(AIA,255);
  analogWrite(BIB,255);
  analogWrite(BIA,0);
}
