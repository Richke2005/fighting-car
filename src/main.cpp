#include <Arduino.h>
#include <config.hpp>
//#include <Servo.h>
#include <HCSR04.h>
#include <SoftwareSerial.h>
#include "../lib/senaiCar/ardCar/ardCar.hpp"

SoftwareSerial bluetooth(RX, TX);
HBridgeMotor bridge1(H1_PIN1A, H1_PIN2A, H1_PIN1B, H1_PIN2B);
HBridgeMotor bridge2(H2_PIN1A, H2_PIN2A);
ArdCar car;
//Servo servY;

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  bridge2.initialize();
  car.attachBattery(PIN_BATTERY);
  car.attachLeds(RED_LED, YELLOW_LED, GREEN_LED);
  //servY.attach(PIN_SERVO_Y);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

static char bCommand = 0;
  static char bCommandNew = 0;

void loop() {
  

  if(bluetooth.available()){
    bCommandNew = bluetooth.read();
  }

  if (bCommandNew != bCommand)
    Serial.println(bCommandNew, HEX);

  bCommand = bCommandNew;

  car.controlBatteryLeds();
  car.controllerForward(&bCommand, &bluetooth);
  car.controllerBackward(&bCommand, &bluetooth);
  car.controllerStop(&bCommand, &bluetooth);
  car.controllerTurnRight(&bCommand, &bluetooth);
  car.controllerTurnLeft(&bCommand, &bluetooth);
  car.rotationRight(&bCommand, &bluetooth);
  car.rotationLeft(&bCommand, &bluetooth);
  car.controllerStopDirection(&bCommand, &bluetooth);
  //car.controllerServAxisY(&bCommand, &bluetooth);

  delay(5);
}