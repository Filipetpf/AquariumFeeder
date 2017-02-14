#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* network_ssid = "<SSID>";
const char* network_password = "<PASSWORD>";
const char* network_ssid_ap = "Rede NodeMCU";

void connectWifi(void) {
  while(WiFi.waitForConnectResult() != WL_CONNECTED){
    WiFi.begin(network_ssid, network_password);
    Serial.println("WiFi failed, retrying.");
  }
}

void setupWifi(void){
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(network_ssid, network_password);

  connectWifi();
}

void setupWifiAP(void) {
  WiFi.softAP(network_ssid_ap, network_password);
}
