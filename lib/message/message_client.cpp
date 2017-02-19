#include "RestClient.h"
#include <ArduinoJson.h>
#include <fish_feeder.cpp>
#include <stdlib.h>
#include <string.h>

char post_body[] = "{}";
RestClient client = RestClient("<HOST>", 443, "<FINGERPRINT>");

int send_message(char * message) {
  char endpoint[100];
  strcpy(endpoint, "/messages/");
  strcat(endpoint, message);

  return client.post(endpoint, post_body);
}

int check_feed_schedule() {
  String json;
  client.get("/messages", &json);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    Serial.println("parseObject() failed");
  }

  int size = root["size"];

  int i;
  for(i = 0; i < size; i++) {
    const char* message = root["messages"][i];
    char *feed = strstr(message, "feed");
    char *fish = strstr(message, "fish");
    Serial.println(message);
    if(feed != NULL && fish != NULL) {
      feed_fish();
      send_message("The swiming creatures has been feed");
    }
  }

  return size;
}
