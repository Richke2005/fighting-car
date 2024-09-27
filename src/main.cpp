#include <Arduino.h>
#include <SoftwareSerial.h>
#include <hBridgeMotor.hpp>
#include <config.hpp>

HBridgeMotor bridge1(PIN1A, PIN2A, PIN1B, PIN2B);
// SoftwareSerial bluetooth(RX, TX);

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      char command = Serial.read();
      if(command == 'l'){
        bridge1.continuousSetMotorA(HIGH, 1);
      }
      if(command == 'r'){
        bridge1.continuousSetMotorA(HIGH, 2);
      }
      if(command == 's'){
        bridge1.continuousSetMotorA(LOW, 0);
      }
    }
  }
