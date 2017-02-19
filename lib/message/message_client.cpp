#include "RestClient.h"
#include <ArduinoJson.h>
#include <fish_feeder.cpp>
#include <stdlib.h>
#include <string.h>
#include <config.h>

RestClient client = RestClient(GATEWAY_ADDRESS, 443, GATEWAY_SSL_FINGERPRINT);

int send_message(char * message) {
  char endpoint[100];
  strcpy(endpoint, "/messages/");
  strcat(endpoint, message);

  return client.post(endpoint, "{}");
}

int check_feed_schedule() {
  String json;
  client.get("/messages", &json);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);

  int size = root["size"];
  int i;

  for(i = 0; i < size; i++) {
    const char* message = root["messages"][i];
    char *feed = strstr(message, "feed");
    char *fish = strstr(message, "fish");
    Serial.println(message);
    if(feed != NULL && fish != NULL) {
      feed_fish();
      send_message((char*)"The swiming creatures has been feed");
    }
  }

  return size;
}
