#include <message_client.h>

RestClient client = RestClient(GATEWAY_ADDRESS, 443, GATEWAY_SSL_FINGERPRINT);

int send_message(char * message, char * user_id, char * bot_id) {
  char endpoint[100];
  strcpy(endpoint, "/from/");
  strcat(endpoint, bot_id);
  strcat(endpoint, "/to/");
  strcat(endpoint, user_id);
  strcat(endpoint, "/messages/");
  strcat(endpoint, message);
  strcat(endpoint, "?token=");
  strcat(endpoint, AUTH_TOKEN);

  return client.post(endpoint, "{}");
}

void check_messages(void) {
  char endpoint[100];
  strcpy(endpoint, "/messages?");
  strcat(endpoint, COMMANDS);
  strcat(endpoint, ALLOWED_USERS);
  strcat(endpoint, "&token=");
  strcat(endpoint, AUTH_TOKEN);

  String json;
  int status = client.get(endpoint, &json);

  if(status == 200) {
    process_message(json);
  }
}

void process_message(String json) {

  int str_len = json.length() + 1;
  char json_char_array[str_len];
  json.toCharArray(json_char_array, str_len);

  aJsonObject* root = aJson.parse(json_char_array);

  int command_count = aJson.getObjectItem(root, "size")->valueint;
  aJsonObject* messages = aJson.getObjectItem(root, "messages");

  for(int i = 0; i < command_count; i++) {
      open_door();
      aJsonObject* message = aJson.getArrayItem(messages, i);
      const char* user_id = aJson.getObjectItem(message, "user_id")->valuestring;
      const char* bot_id = aJson.getObjectItem(message, "bot_id")->valuestring;

      send_message((char*) "The Door is open", (char*) user_id, (char*) bot_id);
  }
}
