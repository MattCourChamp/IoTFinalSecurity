#include <Arduino.h>
#include <WiFiNINA.h>
#include <PubSubClient.h>
#include <Arduino_MKRIoTCarrier.h>
#include <ArduinoIoTCloud.h>
#include <SNU.h>
#include "config.h"
MKRIoTCarrier carrier;

void setup() {
  carrier.begin();
  carrier.noCase();
  carrier.Light.gestureAvailable();
  carrier.Light.readGesture();
}

void loop() {
  if(carrier.Light.gestureAvailable()){
    uint8_t gesture = carrier.Light.readGesture();
    Serial.print("Gesture: ");
    if(gesture == UP){
      Serial.println("UP");
    }
    if(gesture == DOWN){
      Serial.println("DOWN");
    }
    if(gesture == RIGHT){
      Serial.println("RIGHT");
    }
    if(gesture == LEFT){
      Serial.println("LEFT");
    }
  }
}