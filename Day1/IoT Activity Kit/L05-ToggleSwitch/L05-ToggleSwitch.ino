#define SWPIN D7
#define LEDPIN D0
int buttonState = 0;
int ledState = 0;

void setup() {
    pinMode(LEDPIN,OUTPUT);
    pinMode(SWPIN,INPUT);
}
void loop() {
  int  reading = digitalRead(SWPIN);
  
  if(buttonState != reading){
    delay(300);
    buttonState = reading;
    if (buttonState == LOW) {
      ledState = !ledState;
    }
  }
  
  digitalWrite(LEDPIN,ledState);
}
