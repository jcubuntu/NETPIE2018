int brightness = 0;
int fadeAmount = 10;

void setup() {
  pinMode(D0, OUTPUT);
}

void loop() {
  analogWrite(D0, brightness);
  brightness = brightness + fadeAmount;
  
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  delay(100);
}
