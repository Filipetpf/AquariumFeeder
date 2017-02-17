#include "Servo.h"

int servoPin = 14;
int servoAngle = 0;
Servo servo;

void setup_fish_feeder(void) {
  servo.attach(servoPin);
}

void feed_fish() {
  servo.write(30);
  delay(5000);
  servo.write(110);
  delay(10000);
}
