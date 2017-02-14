#include <wifi.h>
#include <update_server.h>
#include <Servo.h>

int servoPin = 14;
int servoAngle = 0;

Servo servo;

void setup() {
  Serial.begin(9600);

  // setupWifi();
  // setupUpdateServer();

  servo.attach(servoPin);
}

void feedFish() {
  servo.write(30);
  delay(5000);
  servo.write(110);
  delay(10000);
}

void loop() {
  // connectWifi();
  // loopUpdateServer();

  feedFish();
  delay(24*60*60*1000);
}
