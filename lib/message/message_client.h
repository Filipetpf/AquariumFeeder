#include "RestClient.h"
#include <fish_feeder.cpp>
#include <config.h>
#include <aJSON.h>

int send_message(char * message, char * user_id, char * bot_id);

void check_messages(void);

void process_message(String json);
