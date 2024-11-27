#include "./car.hpp"

Car::Car() : pinBattery(-1), battery(0.0), velocity(0.0), objectRadar(0.0) {}

Car::Car(uint8_t pin){
    if(pin < 0 || pin > 13) 
        Serial.println("Invalid pin for battery: " + (String) pin);
        
    this->pinBattery = pin;
    pinMode(this->pinBattery, INPUT);
    this->battery = (float) 12 * analogRead(this->pinBattery) / 1024;
}

void Car::attachBattery(uint8_t pin){
    if(this->pinBattery != -1) 
        Serial.println("Car aready have one port in use and will be changed to: " + (String) pin);
    
    this->pinBattery = pin;
    pinMode(this->pinBattery, INPUT);
}

float Car::getBattery(){
    int valueOfBytes = analogRead(this->pinBattery);
    this->battery = (float) 12 * valueOfBytes / 1024;
    return this->battery;
}

void Car::controlBatteryLeds(){
    float batteryPercent = this->getBatteryToPercent();
    if(batteryPercent > 50 && batteryPercent != -1){
        digitalWrite(this->leds.greenLed, HIGH);
        digitalWrite(this->leds.yellowLed, LOW);
        digitalWrite(this->leds.redLed, LOW);
    } else if(batteryPercent > 25 && batteryPercent != -1){
        digitalWrite(this->leds.greenLed, LOW);
        digitalWrite(this->leds.yellowLed, HIGH);
        digitalWrite(this->leds.redLed, LOW);
    } else {
        digitalWrite(this->leds.greenLed, LOW);
        digitalWrite(this->leds.yellowLed, LOW);
        digitalWrite(this->leds.redLed, HIGH);
    }
}

float Car::getBatteryToPercent(){
    return (this->getBattery() * 100) / 12;
}

void Car::attachLeds(uint8_t redLed, uint8_t yellowLed, uint8_t greenLed){
    this->leds.redLed = redLed;
    this->leds.yellowLed = yellowLed;
    this->leds.greenLed = greenLed;
    pinMode(this->leds.redLed, OUTPUT);
    pinMode(this->leds.yellowLed, OUTPUT);
    pinMode(this->leds.greenLed, OUTPUT);
}