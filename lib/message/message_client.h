#include "RestClient.h"

char post_body[] = "{}";
RestClient client = RestClient("ec2-54-214-85-187.us-west-2.compute.amazonaws.com");

int send_message(char * message) {
  char endpoint[100];
  strcpy(endpoint, "/messages/");
  strcat(endpoint, message);

  return client.post(endpoint, post_body);
}
