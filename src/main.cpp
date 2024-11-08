#include <Arduino.h>
#include <config.hpp>
#include <SoftwareSerial.h>
#include "../lib/senaiCar/ardCar/ardCar.hpp"

SoftwareSerial bluetooth(RX, TX);
HBridgeMotor bridge1(H1_PIN1A, H1_PIN2A, H1_PIN1B, H1_PIN2B);
HBridgeMotor bridge2(H2_PIN1A, H2_PIN2A);
ArdCar car;

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  bridge2.initialize();
  car.attachBattery(PIN_BATTERY);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()){
    char bCommand = bluetooth.read();
    Serial.println(bCommand);
    ArdCar::controllerForward(&bCommand, &bluetooth);
    ArdCar::controllerTurnRight(&bCommand, &bluetooth);
    ArdCar::controllerTurnLeft(&bCommand, &bluetooth);
    ArdCar::controllerStopDirection(&bCommand, &bluetooth);
    ArdCar::controllerBackward(&bCommand, &bluetooth);
    ArdCar::controllerStop(&bCommand, &bluetooth);
  }
}
