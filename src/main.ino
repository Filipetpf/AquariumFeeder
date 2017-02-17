#include <wifi.h>
#include <message_client.h>
#include <fish_feeder.h>

void setup() {
  Serial.begin(9600);
  setup_fish_feeder();
}

void loop() {
  connectWifi();
  feed_fish();
  send_message("The swiming creatures has been feed");
}
