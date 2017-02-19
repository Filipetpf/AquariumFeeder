#include <wifi.h>
#include <message_client.cpp>

void setup() {
  Serial.begin(9600);
  setup_fish_feeder();
}

void loop() {
  connectWifi();
  check_messages();
}
