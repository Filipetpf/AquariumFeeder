#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* network_ssid = "<SSID>";
const char* network_password = "<PASSWORD>";

void connectWifi(void) {
  while(WiFi.waitForConnectResult() != WL_CONNECTED){
    WiFi.begin(network_ssid, network_password);
    Serial.println("WiFi failed, retrying.");
  }
}
