/*
    This sketch sends data via HTTP GET requests to data.sparkfun.com service.

    You need to get streamId and privateKey at data.sparkfun.com and paste them
    below. Or just customize this script to talk to other HTTP servers.

*/

#include <ESP8266WiFi.h>

const char* ssid     = "A101";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(BUILTIN_LED, OUTPUT);  // initialize onboard LED as output
  WiFi.mode(WIFI_STA);
  digitalWrite(BUILTIN_LED, HIGH);  // turn off LED
}

void loop() {

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network.*/

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(5);
    //Serial.print(".");
  }
  
  digitalWrite(BUILTIN_LED, LOW);  // turn on LED


  Serial.print("WiFi connected.   ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());

  delay(2000);

  Serial.println("closing connection");
  WiFi.disconnect();
  while (WiFi.status() == WL_CONNECTED) {
    delay(5);
  }
  
  digitalWrite(BUILTIN_LED, HIGH); // turn off LED
  delay(2000);
}

