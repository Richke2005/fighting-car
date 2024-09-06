#include <Arduino.h>
#include <config.hpp>
#include <hBridgeMotor.hpp>
#include <SoftwareSerial.h>
// put function declarations here:
const byte TX = 4;
const byte RX = 5;

HBridgeMotor bridge1(PIN1A, PIN2A);
SoftwareSerial bluetooth(TX, RX);

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read() == 'a'){
    bridge1.setMotorA((float) 0.0, 1);
  }
  if(Serial.read() == 'i')
    bridge1.setMotorA(true, 2);
  
  if(Serial.read() == 'b')
  	bridge1.setMotorB(true, 1);
  
  if(Serial.read() == 'x')
  	bridge1.setMotorB(true, 2);
}
