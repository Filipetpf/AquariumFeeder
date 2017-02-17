#include <wifi.h>
#include <message_client.cpp>
#include <fish_feeder.cpp>

void setup() {
  Serial.begin(9600);
  setup_fish_feeder();
}

void loop() {
  connectWifi();
  // feed_fish();
  // send_message("The swiming creatures has been feed");

  char ** messages;
  get_messages(messages);
}
