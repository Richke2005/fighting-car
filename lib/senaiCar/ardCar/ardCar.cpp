#include "./ardCar.hpp"

ArdCar::ArdCar() : Car() {};

void ArdCar::controllerForward(char command, SoftwareSerial* response) {
    if (command == 'f') {
        this->speedF = 128;
    }
    // Verifica se é hora de atualizar a velocidade
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        if (this->speedF != 0) {
            this->speedF = constrain(this->speedF + 1, 0, 255);
            Serial.println(this->speedF);
            bridge1.continuousSetMotorA(this->speedF, 1);
            bridge2.continuousSetMotorA(this->speedF, 1);
        }
    }
}


void ArdCar::controllerBackward(char command, SoftwareSerial* response){
    if (command == 'b') {
        this->speedF = 128;
    }
    // Verifica se é hora de atualizar a velocidade
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        if (this->speedF != 0) {
            this->speedF = constrain(this->speedF + 1, 0, 255);
            Serial.println(this->speedF);
            bridge1.continuousSetMotorA(this->speedF, 2);
            bridge2.continuousSetMotorA(this->speedF, 2);
        }
    }
}

void ArdCar::controllerTurnRight(char command, SoftwareSerial* response){
    if (command == 'r') {
        this->speedR = 128;
    }
    // Verifica se é hora de atualizar a velocidade
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        if (this->speedR != 0) {
            this->speedR = constrain(this->speedR + 1, 0, 255);
            Serial.println(this->speedR);
            bridge1.continuousSetMotorB(this->speedR, 1);
        }
    }
}

void ArdCar::controllerTurnLeft(char command, SoftwareSerial* response){
    if (command == 'l') {
        this->speedL = 128;
    }
    // Verifica se é hora de atualizar a velocidade
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        if (this->speedL != 0) {
            this->speedL = constrain(this->speedL + 1, 0, 255);
            Serial.println(this->speedL);
            bridge1.continuousSetMotorB(this->speedL, 1);
        }
    }
}

void ArdCar::controllerStopDirection(char command, SoftwareSerial* response){
    if(command == 'd'){
        this->speedR = 0;
        this->speedL = 0;
        bridge1.continuousSetMotorB(speedR, 1);
        bridge1.continuousSetMotorB(speedL, 2);
    }
}

void ArdCar::controllerStop(char command, SoftwareSerial* response){
    if(command == 's'){
        this->speedF = 0;
        bridge1.continuousSetMotorA(speedF, 1);
        bridge2.continuousSetMotorA(speedF, 1);
    }
}

void ArdCar::rotationRight(char command, SoftwareSerial* response){
    if (command == 'R') {
        this->speedF = 128;
    }
    // Verifica se é hora de atualizar a velocidade
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        if (this->speedF != 0) {
            this->speedF = constrain(this->speedF + 1, 0, 255);
            Serial.println(this->speedF);
            bridge1.continuousSetMotorA(this->speedF, 1);
            bridge1.continuousSetMotorB(this->speedF, 1);
            bridge2.continuousSetMotorA(this->speedF, 2);
        }
    }
}

void ArdCar::rotationLeft(char command, SoftwareSerial* response){
    if (command == 'L') {
        this->speedF = 128;
    }
    // Verifica se é hora de atualizar a velocidade
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        if (this->speedF != 0) {
            this->speedF = constrain(this->speedF + 1, 0, 255);
            Serial.println(this->speedF);
            bridge1.continuousSetMotorA(this->speedF, 2);
            bridge1.continuousSetMotorB(this->speedF, 2);
            bridge2.continuousSetMotorA(this->speedF, 1);
        }
    }
}

void ArdCar::refreshSpeed (const char * const command){
    if (*command == 'f' || *command == 'b' || *command == 'R' || *command == 'L'){
        if (speedL == 0)
            speedL = 128;
        else
            speedL = constrain(speedL + 1, 0, 255);

        if (speedR == 0)
            speedR  = 128;
        else
            speedR = constrain(speedR + 1, 0, 255);
    }
    
    if (*command == 'r' || *command == 'l' || *command == 'R' || *command == 'L'){
        if (speedF == 0)
            speedF  = 128;
        else
            speedF = constrain(speedF + 1, 0, 255);
    }
    
    if (*command == 'd'){
        speedF = 0;
    }
    
    if (*command == 's'){
        speedR = 0;
        speedL = 0;
    }

    Serial.println(speedR);
}

void ArdCar::controllerServAxisY(char command, SoftwareSerial* response){
    if(command == '-'){
        int angle = servY.read();
        servY.write(angle - 27);
    }

    if(command == '+'){
        int angle = servY.read();
        servY.write(angle + 27);
    }
}