#include <Arduino.h>
#include <config.hpp>
#include <Servo.h>
#include <HCSR04.h>
#include <SoftwareSerial.h>
#include "../lib/senaiCar/ardCar/ardCar.hpp"

SoftwareSerial bluetooth(RX, TX);
HBridgeMotor bridge1(H1_PIN1A, H1_PIN2A, H1_PIN1B, H1_PIN2B);
HBridgeMotor bridge2(H2_PIN1A, H2_PIN2A);
ArdCar car;

Servo serv;
UltraSonicDistanceSensor radar(TRIGGER_PIN, ECHO_PIN);

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  bridge2.initialize();
  car.attachBattery(PIN_BATTERY);
  car.attachLeds(RED_LED, YELLOW_LED, GREEN_LED);
  serv.attach(PIN_SERVO);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()){
    char bCommand = bluetooth.read();
    car.controllerForward(&bCommand, &bluetooth);
    car.controllerBackward(&bCommand, &bluetooth);
    car.controllerStop(&bCommand, &bluetooth);
    car.controllerTurnRight(&bCommand, &bluetooth);
    car.controllerTurnLeft(&bCommand, &bluetooth);
    car.controllerStopDirection(&bCommand, &bluetooth);
  }else{
    car.controlBatteryLeds();
    //testing radar
    float distance = radar.measureDistanceCm();
    Serial.println(distance);

    if(Serial.available()){
      char sCommand = Serial.read();
      if(sCommand == 'p')
        serv.write(90);
    }
  }
}