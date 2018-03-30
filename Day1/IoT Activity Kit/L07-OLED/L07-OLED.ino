#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_RESET  -1
Adafruit_SSD1306 display(OLED_RESET);


void setup() {
  
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  delay(2000);
  display.clearDisplay();           

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("TEST TEXT OLED");
  display.display();
  display.clearDisplay();
}

void loop() {
 

}
