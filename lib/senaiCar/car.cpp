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