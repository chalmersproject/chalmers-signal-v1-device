/*

   ___ _         _                    ___ _                _ _
  / __| |_  __ _| |_ __  ___ _ _ ___ / __(_)__ _ _ _  __ _| | |
 | (__| ' \/ _` | | '  \/ -_) '_(_-< \__ \ / _` | ' \/ _` | |_|
  \___|_||_\__,_|_|_|_|_\___|_| /__/ |___/_\__, |_||_\__,_|_(_)
                                           |___/
See README for installation instructions

*/

#define USE_SERIAL Serial
//API Keys, SSIDs, Passwords
#include "secrets.h"
//Libraries and declarations
#include "declarations.h"
int ReCalc;

void setup() {

  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3D for 128x64
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);

  //neopixel setup
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  ReCalc = map(analogRead(Pot), 0, 960, 0, 70);
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(ReCalc);
  display.display();

  rainbow(20);
  delay(300);

}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
