/**
  The Chalmers Signal Client Script

  Based on the example code from:
    BasicHTTPClient.ino
    FirebaseDemo_ESP8266.ino

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>
#include <FirebaseArduino.h>

#include <declare.h>
#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;
#define Button D3
#define LED D2

void setup() {
  USE_SERIAL.begin(115200);
  //Do some shitty Serial Console Graphics stuff
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println("ClIENT STARTING UP!!!");
  USE_SERIAL.println("======================");
  USE_SERIAL.println("======================");

  //Initialize the LED and Button Pins
  pinMode(LED, OUTPUT);
  pinMode(Button, INPUT);

  //Play an "I'm Awake" thingy on the LED
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
  }
  init_firebase_connection();
}

//Initialize a global "Value" variable. It stores
//whether the button is in "Active Mode"
int value = -1; //init value to OFF

void loop() {
  if (button_pressed()) {
    update_value();
    push_value();
//if acknowledgement isn't recieved, continue to flash_led
//also, continue to push_value() and check push_acknowledged()
    if(push_acknowledged() == false){
      while (push_acknowledged() == false) {
        flash_led();
        push_value();
        if (push_acknowledged) {
          break;
        }
      }
    }
//if value is high, and push_acknowledged(), write LED high
    if ((value == 1) && push_acknowledged()) {
      USE_SERIAL.println("value HIGH");
      flash_led();
      if (push_acknowledged()) {
        digitalWrite(LED, HIGH);
      }
    } else {
      USE_SERIAL.println("value LOW");
      digitalWrite(LED, LOW);
    }
  }
}

void init_firebase_connection() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //more silly Serial Console graphics stuff
  USE_SERIAL.println("=====================");
  USE_SERIAL.println("connecting to firebase!!!");
  USE_SERIAL.println("======================");
  USE_SERIAL.println("======================");

  USE_SERIAL.println("==============");
  USE_SERIAL.println("acquiring internet connection!!!");
  USE_SERIAL.println("==============");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED) {
    USE_SERIAL.println("Connected to internet!!");
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

bool button_pressed() {
  if (digitalRead(Button) == LOW) {
    //debounce button;
    delay(200);
    //more Serial console graphics
    USE_SERIAL.println("======================");
    USE_SERIAL.println("======================");
    USE_SERIAL.println("BUTTON PRESSED!!");
    USE_SERIAL.println("======================");
    USE_SERIAL.println("======================");
    return true;
  } else {
    return false;
  }
}
//value represents whether the button was pressed
//into an "ON" state or "OFF" state
void update_value() {
  value *= -1; // toggle the value
}
void push_value() {
  //push the updated value to the database
  //then print in the console if the push was a success
  Firebase.setString("message", "hello juan");
  USE_SERIAL.print("Status of last Set-String: ");
  USE_SERIAL.println(Firebase.success());
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /message failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);
}
void flash_led() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED, HIGH);
    USE_SERIAL.println("LED, ON!!!!");
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
}
bool push_acknowledged() { // check for acknowledgement from server
  return true;
}
