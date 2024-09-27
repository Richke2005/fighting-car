#include <Arduino.h>
#include <config.hpp>
#include <hBridgeMotor.hpp>

HBridgeMotor bridge1(PIN1A, PIN2A);

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char command = Serial.read();
      if(command == '2'){
      bridge1.setMotorA(true, 2);
      }
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
