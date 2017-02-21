#include "Arduino.h"
#define DOOR_PIN 14

void setup_door(void) {
  pinMode(DOOR_PIN, OUTPUT);
}

void open_door(void) {
  digitalWrite(DOOR_PIN, HIGH);
  delay(1000);
  digitalWrite(DOOR_PIN, LOW);
}
