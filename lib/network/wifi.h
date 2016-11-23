#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* network_ssid = "<SSID>";
const char* network_password = "<PASSWORD>";
const char* network_ssid_ap = "Rede NodeMCU";

// config static IP
IPAddress ip(192, 168, 1, 150);
IPAddress gateway(192, 168, 1, 0);
IPAddress subnet(255, 255, 255, 0);

void connectWifi(void) {
  while(WiFi.waitForConnectResult() != WL_CONNECTED){
    WiFi.begin(network_ssid, network_password);
    Serial.println("WiFi failed, retrying.");
  }
}

void setupWifi(void){
  WiFi.mode(WIFI_AP_STA);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(network_ssid, network_password);

  connectWifi();
}

void setupWifiAP(void) {
  WiFi.softAP(network_ssid_ap, network_password);
}
