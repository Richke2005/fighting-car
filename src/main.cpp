#include <Arduino.h>
#include <config.hpp>
#include <SoftwareSerial.h>
#include <hBridgeMotor.hpp>

// put function declarations here:
const byte TX = 8;
const byte RX = 7;

HBridgeMotor bridge1(PIN1A, PIN2A);
SoftwareSerial bluetooth(RX, TX);

void setup() {
  // put your setup code here, to run once:
  bridge1.initialize();
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bluetooth.available()){
    char letra = bluetooth.read();
    if(letra == '1'){
      bridge1.setMotorA(true, 1);
    }
    if(letra == '2'){
      bridge1.setMotorA(true, 2);
    }
  }

  if(Serial.available()){
      if(Serial.read() == '2'){
      bridge1.setMotorA(true, 2);
    }
  }
}
