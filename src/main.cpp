#include <Arduino.h>
#include <config.hpp>
#include <SoftServo.h>
#include "../lib/senaiCar/ardCar/ardCar.hpp"


SoftwareSerial bluetooth(RX, TX);
HBridgeMotor bridge1(H1_PIN1A, H1_PIN2A, H1_PIN1B, H1_PIN2B);
HBridgeMotor bridge2(H2_PIN1A, H2_PIN2A);
SoftServo servY;
ArdCar car;
char bCommand = 0;

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  bridge2.initialize();
  car.attachBattery(PIN_BATTERY);
  car.attachLeds(RED_LED, YELLOW_LED, GREEN_LED);
  servY.attach(PIN_SERVO_Y);
  servY.delayMode();
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  servY.tick();
  if(bluetooth.available()){
    bCommand = bluetooth.read();
  }
  car.controlBatteryLeds();
  car.controllerForward(bCommand);
  car.controllerBackward(bCommand);
  car.controllerStop(bCommand);
  car.controllerTurnRight(bCommand);
  car.controllerTurnLeft(bCommand);
  car.controllerStopDirection(bCommand);
  car.controllerRotationRight(bCommand);
  car.controllerRotationLeft(bCommand); 
  car.controllerServAxisY(bCommand);
  //car.controllerServAttack(bCommand);
}