#include "./ardCar.hpp"

ArdCar::ArdCar() : Car() {};

void ArdCar::controllerForward(char* command, SoftwareSerial* response){
    if(*command == 'f'){
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
    if(*command == 'b'){
    int dirMA = bridge1.continuousSetMotorA(HIGH, 2);
    int dirMB = bridge2.continuousSetMotorA(HIGH, 2);
        if(dirMA == 0 || dirMB == 0){
            response->println("motors are off");
        }
        response->println("motor A is on, port: " + (String) dirMA);
        response->println("motor B is on, port: " + (String) dirMB);
    }
}

void ArdCar::controllerTurnRight(char* command, SoftwareSerial* response){
    if(*command == 'r'){
    int dirMA = bridge1.continuousSetMotorB(HIGH, 1);
        if(dirMA == 0)
            response->println("motors are off");
        
        response->println("motor A is on, port: " + (String) dirMA);
    }
}

void ArdCar::controllerTurnLeft(char* command, SoftwareSerial* response){
    if(*command == 'l'){
    int dirMA = bridge1.continuousSetMotorB(HIGH, 2);
        if(dirMA == 0)
            response->println("motors are off");
        
        response->println("motor A is on, port: " + (String) dirMA);
    }
}

void ArdCar::controllerStopDirection(char* command, SoftwareSerial* response){
    if(*command == 'd'){
        bridge1.continuousSetMotorB(LOW, 1);
        bridge1.continuousSetMotorB(LOW, 2);
        response->println("Direction is off");
    }
}

void ArdCar::controllerStop(char* command, SoftwareSerial* response){
    if(*command == 's'){
        bridge1.continuousSetMotorA(LOW, 1);
        bridge2.continuousSetMotorA(LOW, 1);
        bridge1.continuousSetMotorB(LOW, 2);
        bridge2.continuousSetMotorA(LOW, 2);
        response->println("motors are off");
    }
}

void ArdCar::rotationRight(char* command, SoftwareSerial* response){
    if(*command == 'R'){
        bridge1.continuousSetMotorA(HIGH, 1);
        bridge1.continuousSetMotorB(HIGH, 1);
        bridge2.continuousSetMotorA(HIGH, 2);

        response->println("motors are on");
    }
}

void ArdCar::rotationLeft(char* command, SoftwareSerial* response){
    if(*command == 'L'){
        bridge1.continuousSetMotorA(HIGH, 2);
        bridge1.continuousSetMotorB(HIGH, 2);
        bridge2.continuousSetMotorA(HIGH, 1);

        response->println("motors are on");
    }
}

void ArdCar::controllerServAxisY(char* command, SoftwareSerial* response){
    if(*command == '-'){
        int angle = servY.read();
        servY.write(angle - 27);
        
    }

    if(*command == '+'){
        int angle = servY.read();
        servY.write(angle + 27);
    }
}