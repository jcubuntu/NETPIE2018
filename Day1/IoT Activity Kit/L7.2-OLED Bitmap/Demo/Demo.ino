
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>

#define OLED_RESET      -1

byte logo [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
  0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF,
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
  0xF0, 0x7F, 0xFE, 0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC2, 0x3F, 0xFC, 0xA3,
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xCF, 0x9F, 0xFC, 0xFB, 0xF0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0x9F, 0x9F, 0xF3, 0xF9, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
  0x3F, 0xCF, 0xF3, 0xFD, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xBF, 0xEF, 0xF3, 0xFC,
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xBF, 0xC7, 0xFB, 0xFC, 0xE0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0x3F, 0xDF, 0xF3, 0xFD, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
  0x9F, 0x8F, 0xF9, 0xF9, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xCF, 0xBF, 0xFC, 0xF3,
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xE0, 0x3F, 0xFE, 0x07, 0xC0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x03, 0xF9, 0xFF, 0xFF, 0x2F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x3F, 0xE6, 0x57, 0xFA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x40, 0x01, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x2D, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0xFC, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x6D, 0xEF,
  0xF8, 0x00, 0x01, 0x60, 0x03, 0xDA, 0x00, 0x00, 0x00, 0x03, 0x9F, 0x80, 0x18, 0x00, 0x03, 0xF8,
  0x07, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xDF, 0x00, 0xFA, 0x51, 0x43, 0xB9, 0x1E, 0xAB, 0x80, 0x00,
  0x00, 0x01, 0x7F, 0x1F, 0xF7, 0xFF, 0xFF, 0x3F, 0xF8, 0x01, 0x80, 0x00, 0x00, 0x01, 0x8E, 0x3F,
  0xFF, 0xBF, 0xFF, 0xDF, 0xFC, 0x39, 0x80, 0x00, 0x00, 0x03, 0x0E, 0x3F, 0xF8, 0x0C, 0x03, 0x39,
  0xCE, 0x1F, 0xC0, 0x00, 0x00, 0x01, 0x9E, 0x3C, 0x39, 0xC4, 0x73, 0x19, 0xCF, 0x8F, 0x80, 0x00,
  0x00, 0x01, 0x8E, 0x1E, 0x38, 0x04, 0xE1, 0x19, 0xCF, 0xC3, 0x00, 0x00, 0x00, 0x03, 0x1E, 0x1F,
  0x38, 0xFE, 0x73, 0x31, 0xCD, 0x63, 0x80, 0x00, 0x00, 0x01, 0x8F, 0x00, 0x19, 0xFC, 0x73, 0x19,
  0xCC, 0x41, 0xC0, 0x00, 0x00, 0x01, 0x8F, 0x80, 0x38, 0x0E, 0x73, 0x18, 0x0E, 0x01, 0x80, 0x00,
  0x00, 0x01, 0xFB, 0xF6, 0xBE, 0xEF, 0xFF, 0xFF, 0xCF, 0x69, 0xC0, 0x00, 0x00, 0x00, 0x79, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x20, 0x5F, 0xE3, 0x5B, 0x55, 0x51,
  0x7D, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3D, 0x80, 0x00, 0x00, 0x01, 0xFF, 0x00, 0x80, 0x00, 0x10, 0x40, 0x00, 0x76, 0x80, 0x00,
  0x00, 0x03, 0x47, 0xFB, 0xEF, 0xBF, 0x7F, 0xFB, 0xDF, 0xD2, 0xC0, 0x00, 0x00, 0x03, 0x90, 0xFF,
  0xFF, 0xFF, 0xFB, 0xFF, 0xEF, 0x05, 0xC0, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x0D, 0x03, 0x80, 0x00, 0x00, 0x00, 0xE0, 0x10, 0x00, 0x40, 0x00, 0x00, 0x04, 0x03, 0x80, 0x00,
  0x00, 0x00, 0x38, 0x39, 0xF9, 0xE3, 0xE7, 0xCF, 0xDC, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x78,
  0xD9, 0x73, 0xE6, 0x67, 0x2E, 0x5C, 0x00, 0x00, 0x00, 0x00, 0x07, 0x35, 0xB9, 0x3B, 0x24, 0xC3,
  0x1C, 0x68, 0x00, 0x00, 0x00, 0x00, 0x07, 0xBC, 0xD9, 0xB3, 0xF6, 0xE3, 0x26, 0xE0, 0x00, 0x00,
  0x00, 0x00, 0x03, 0xC4, 0x90, 0xC3, 0x67, 0x81, 0x33, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xD0,
  0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x02, 0x10, 0x00, 0x20,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFB, 0xFF, 0xFF, 0xBF, 0xFE, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x1F, 0x7D, 0xF7, 0xD7, 0xBE, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.drawBitmap(15, 0,  logo, 96, 63, 1);
  display.display(); 
}

void loop() {

}
