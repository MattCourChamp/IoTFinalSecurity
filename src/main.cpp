#include <Arduino.h>
#include <WiFiNINA.h>
#include <PubSubClient.h>
#include <Arduino_MKRIoTCarrier.h>
#include <ArduinoIoTCloud.h>
#include <SNU.h>
#include "config.h"
#include "IFTTTWebhookMKG.h"
MKRIoTCarrier carrier;

#define IFTTT_KEY "hPLWpmLBmb_OQPTCVeFXXFj3Tf4kZz9lTfDqfU5OmBR"  // Key provided by https://ifttt.com/maker_webhooks 
#define IFTTT_EVENT "security_trigger"  //Event Name, you pick 

// Connects to WiFi
void connectWiFi()
{
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connecting to WiFi..");
        WiFi.begin(SSID, PASSWORD);
        delay(500);
    }

    Serial.println("Connected!");
}

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup() {
  carrier.begin();
  carrier.noCase();
  carrier.Light.gestureAvailable();
  carrier.Light.readGesture();
  connectWiFi();
}

// Waits for motion, detects motion type, sends motion to a Google Sheet using IFTTT
void loop() {
  if(carrier.Light.gestureAvailable()){
    uint8_t gesture = carrier.Light.readGesture();
    Serial.print("Gesture: ");
    if(gesture == UP){
      Serial.println("UP");
      Serial.println("Sending IFTTT messages");
      callWebhook(IFTTT_EVENT,IFTTT_KEY,"UP"); // IFTTT call
      Serial.println("Sent");
    }
    if(gesture == DOWN){
      Serial.println("DOWN");
      Serial.println("Sending IFTTT messages");
      callWebhook(IFTTT_EVENT,IFTTT_KEY, "DOWN"); // IFTTT call
      Serial.println("Sent");
    }
    if(gesture == RIGHT){
      Serial.println("RIGHT");
      Serial.println("Sending IFTTT messages");
      callWebhook(IFTTT_EVENT,IFTTT_KEY, "RIGHT"); // IFTTT call
      Serial.println("Sent");
    }
    if(gesture == LEFT){
      Serial.println("LEFT");
      Serial.println("Sending IFTTT messages");
      callWebhook(IFTTT_EVENT,IFTTT_KEY, "LEFT"); // IFTTT call
      Serial.println("Sent");
    }
  }
}