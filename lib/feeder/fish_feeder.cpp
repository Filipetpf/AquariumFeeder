#include "Servo.h"

#define SERVO_OPEN 20
#define SERVO_CLOSED 110

int servoPin = 14;
int servoAngle = 0;
Servo servo;

void feed_fish() {
  servo.attach(servoPin);

  servo.write(SERVO_OPEN);
  delay(3000);
  servo.write(SERVO_CLOSED);
  delay(1000);

  servo.detach();
}
