#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <config.h>

void connectWifi(void) {
  while(WiFi.waitForConnectResult() != WL_CONNECTED){
    WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
    Serial.println("WiFi failed, retrying.");
  }
}
