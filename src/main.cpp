#include <Arduino.h>
#include <config.hpp>
#include <hBridgeMotor.hpp>
// put function declarations here:
HBridgeMotor bridge1(PIN1A, PIN2A);

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read() == 'a'){
  	bridge1.setMotorA(true, 1);
  }
  if(Serial.read() == 'i')
    bridge1.setMotorA(true, 2);
  
  if(Serial.read() == 'b')
  	bridge1.setMotorB(true, 1);
  
  if(Serial.read() == 'x')
  	bridge1.setMotorB(true, 2);
}