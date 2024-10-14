#include "./ardCar.hpp"

ArdCar::ArdCar() : Car() {};
ArdCar::ArdCar(uint8_t pin) : Car(pin) {};

void ArdCar::controllerForward(char* command, SoftwareSerial* response){
    if(*command == 'l'){
    int dirMA = bridge1.continuousSetMotorA(HIGH, 1);
    int dirMB = bridge2.continuousSetMotorA(HIGH, 1);
        if(dirMA == 0 || dirMB == 0){
            response->println("motors are off");

        }
        response->println("motor A is on, port: " + (String) dirMA);
        response->println("motor B is on, port: " + (String) dirMB);
    }
}

void ArdCar::controllerBackward(char* command, SoftwareSerial* response){
    if(*command == 'r'){
    int dirMA = bridge1.continuousSetMotorA(HIGH, 2);
    int dirMB = bridge2.continuousSetMotorA(HIGH, 2);
        if(dirMA == 0 || dirMB == 0){
            response->println("motors are off");
        }
        response->println("motor A is on, port: " + (String) dirMA);
        response->println("motor B is on, port: " + (String) dirMB);
    }
}

void ArdCar::controllerStop(char* command, SoftwareSerial* response){
    if(*command == 's'){
        bridge1.continuousSetMotorA(LOW, 0);
        bridge1.continuousSetMotorB(LOW, 0);
        bridge2.continuousSetMotorA(LOW, 0);
        bridge2.continuousSetMotorB(LOW, 0);
        response->println("motors are off");

    }
}