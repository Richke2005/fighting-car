#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <hBridgeMotor.hpp>
#include "./controller/controller.hpp"
#include <config.hpp>

HBridgeMotor bridge1(PIN1A, PIN2A, PIN1B, PIN2B);
SoftwareSerial bluetooth(RX, TX);
Servo servoMotor;


void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  servoMotor.attach(PIN_SERVO);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if(Serial.available()){
    char command = Serial.read();
    char bCommand = bluetooth;
    Controller::controllerForward(&command, &bridge1);
    Controller::controllerBackward(&command, &bridge1);
    Controller::controllerStop(&command, &bridge1);
    if(command == 'q'){
      servoMotor.write(0);
    }
    if(command == 'w'){
      servoMotor.write(90);
    }
  }
}
