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
      char letra = Serial.read();
      bridge1.continuousSetMotorA((letra == 'l') , 1);
  }
};
