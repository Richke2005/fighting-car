#include <Arduino.h>
#include <config.hpp>
#include <hBridgeMotor.hpp>

HBridgeMotor bridge1(PIN1A, PIN2A, PIN1B, PIN2B);

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      char command = Serial.read();
      bridge1.continuousSetMotorA(command);
    }
          
  }