#include <wifi.h>
#include <fish_feeder.h>

void setup() {
  Serial.begin(9600);
  setup_fish_feeder();
}

void loop() {
  connectWifi();
  feed_fish();
}
