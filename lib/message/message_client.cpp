#include <message_client.h>

RestClient client = RestClient(GATEWAY_ADDRESS, 443, GATEWAY_SSL_FINGERPRINT);

int send_message(char * message, char * user_id, char * bot_id) {
  char endpoint[100];
  strcpy(endpoint, "/from/");
  strcat(endpoint, bot_id);
  strcpy(endpoint, "/to/");
  strcat(endpoint, user_id);
  strcpy(endpoint, "/messages/");
  strcat(endpoint, message);

  return client.post(endpoint, "{}");
}

void check_messages(void) {
  char endpoint[100];
  strcpy(endpoint, "/messages?");
  strcat(endpoint, "commands=feed&commands=fish");
  strcat(endpoint, ALLOWED_USERS);

  String json;
  client.get(endpoint, &json);

  StaticJsonBuffer<200> jsonBuffer;
  process_message(jsonBuffer.parseObject(json));
}

void process_message(JsonObject& root) {
  int command_count = root["size"];
  for(int i = 0; i < command_count; i++) {
      feed_fish();
      const char* user_id = root["messages"][i]["user_id"];
      const char* bot_id = root["messages"][i]["bot_id"];
      send_message((char*) "The swiming creatures has been feed", (char*) user_id, (char*) bot_id);
  }
}
