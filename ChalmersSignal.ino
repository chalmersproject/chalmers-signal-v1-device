/*

   ___ _         _                    ___ _                _ _
  / __| |_  __ _| |_ __  ___ _ _ ___ / __(_)__ _ _ _  __ _| | |
 | (__| ' \/ _` | | '  \/ -_) '_(_-< \__ \ / _` | ' \/ _` | |_|
  \___|_||_\__,_|_|_|_|_\___|_| /__/ |___/_\__, |_||_\__,_|_(_)
                                           |___/
See README for installation instructions

*/

#define USE_SERIAL Serial
//Shelter Capacity, API Keys, SSIDs, Passwords
#include "secrets.h"
//Libraries and declarations
#include "declarations.h"
#define Pot A0
int occupancy;
int last_occupancy;
int disp_color;

void setup() {
  USE_SERIAL.begin(115200);
  setup_display();
  setup_led();
  pinMode(Pot,INPUT);
  //run update_display() once, to put a number on the screen when it starts up
  occupancy = check_occupancy();
  update_display(occupancy);
  update_led(occupancy);
  init_firebase_connection();
}
void loop() {
  //store last_occupancy before checking for change
  last_occupancy = occupancy;
  //check occupancy
  occupancy = check_occupancy();
  //check for occupancy change
  if(occupancy != last_occupancy){
    update_display(occupancy);
    update_led(occupancy);
    push_to_database(occupancy);
    while(push_to_database == false){
      push_to_database();
    }
  }
}
int check_occupancy(){
  occupancy = map(analogRead(Pot), 0, 960, 0, SHELTER_CAPACITY);
  return occupancy;
}
void update_display(int occupancy){
  char string = occupancy + " / " + SHELTER_CAPACITY;
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(string);
  display.display();
}
void update_led(int occupancy){
  int i = 0;
  rgb_value = map(occupancy, 0, capacity, 169, 0);
  strip.setPixelColor(i, Wheel((rgb_value) & 255));
}
//while establishing connection, glow LED blue
//once database acknowledgedes, return LED to occupancy color.
bool push_to_database(int occupancy){
  //push the updated value to the database
  //then print in the console if the push was a success
  Firebase.setInt("occupancy", occupancy);
  USE_SERIAL.print("Status of last Set-String: ");
  USE_SERIAL.println(Firebase.success());
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /message failed:");
    Serial.println(Firebase.error());
    return false;
    delay(1000);
  }
}
void setup_display(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3D for 128x64
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
}
void setup_led(){
  //neopixel setup
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
}
void init_firebase_connection() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED) {
    USE_SERIAL.println("Connected to internet!!");
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
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
