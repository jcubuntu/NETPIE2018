#define SWPIN D7
#define LEDPIN D0

void setup() {
  pinMode(LEDPIN, OUTPUT); // Set as output
  pinMode(SWPIN, INPUT);   // Set as input
}

void loop(){
  if (digitalRead(SWPIN) == LOW){
    digitalWrite(LEDPIN,HIGH);
  }
  else{
    digitalWrite(LEDPIN,LOW);
  }
}
