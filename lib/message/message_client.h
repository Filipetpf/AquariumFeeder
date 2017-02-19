#include "RestClient.h"
#include <ArduinoJson.h>
#include <fish_feeder.cpp>
#include <config.h>


int send_message(char * message);

void check_messages(void);

void process_message(JsonObject& root);
