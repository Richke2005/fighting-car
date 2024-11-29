#include <Arduino.h>
#include <config.hpp>
#include <SoftwareServo.h>
#include <SoftwareServo.h>
#include "../lib/senaiCar/ardCar/ardCar.hpp"


SoftwareSerial bluetooth(RX, TX);
HBridgeMotor bridge1(H1_PIN1A, H1_PIN2A, H1_PIN1B, H1_PIN2B);
HBridgeMotor bridge2(H2_PIN1A, H2_PIN2A);
SoftwareServo servY;
ArdCar car;
char bCommand = 0;


void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  bridge2.initialize();
  car.attachBattery(PIN_BATTERY);
  car.attachLeds(RED_LED, YELLOW_LED, GREEN_LED);
  servY.attach(PIN_SERVO_Y);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()){
    bCommand = bluetooth.read();
  }
  car.controlBatteryLeds();
  car.controllerForward(bCommand, &bluetooth);
  car.controllerBackward(bCommand, &bluetooth);
  car.controllerStop(bCommand, &bluetooth);
  car.controllerTurnRight(bCommand, &bluetooth);
  car.controllerTurnLeft(bCommand, &bluetooth);
  car.controllerStopDirection(bCommand, &bluetooth);
  car.rotationRight(bCommand, &bluetooth);
  car.rotationLeft(bCommand, &bluetooth);
  servY.write(90);
}