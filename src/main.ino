#include <wifi.h>
#include <update_server.h>

void setup() {
  Serial.begin(9600);

  setupWifi();
  setupUpdateServer();
}

void loop() {
  connectWifi();
  loopUpdateServer();
}
