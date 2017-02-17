#include "RestClient.h"
#include <ArduinoJson.h>

char post_body[] = "{}";
RestClient client = RestClient("<SERVER>");

int send_message(char * message) {
  char endpoint[100];
  strcpy(endpoint, "/messages/");
  strcat(endpoint, message);

  return client.post(endpoint, post_body);
}

void get_messages(char** messages) {
  String json;
  client.get("/messages", &json);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    Serial.println("parseObject() failed");
  }

  messages = (char**) malloc( sizeof(root["messages"]) * sizeof(char*));

  int i;
  for(i = 0; i < sizeof(root["messages"]); i++) {
    const char* message = root["messages"][i];
    if(sizeof(message) > 0) {
      messages[i] = (char*) message;
    }
  }
}
