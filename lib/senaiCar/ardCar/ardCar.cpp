#include "./ardCar.hpp"

ArdCar::ArdCar() : Car() {};

void ArdCar::controllerForward(char command) {
    if (command != 'f') return; // Retorna imediatamente se o comando não for 'f'

    // Inicializa a velocidade se ainda não foi configurada
    if (this->speedF == 0) {
        this->speedF = 128;
    }

    // Atualiza a velocidade periodicamente
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        this->speedF = constrain(this->speedF + 1, 0, 255);
       
        bridge1.continuousSetMotorA(this->speedF, 1);
        bridge2.continuousSetMotorA(this->speedF, 1);
    }
}



void ArdCar::controllerBackward(char command){
    if (command != 'b') return; // Retorna imediatamente se o comando não for 'f'

    // Inicializa a velocidade se ainda não foi configurada
    if (this->speedF == 0) {
        this->speedF = 128;
    }

    // Atualiza a velocidade periodicamente
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        this->speedF = constrain(this->speedF + 1, 0, 255);
      
        bridge1.continuousSetMotorA(this->speedF, 2);
        bridge2.continuousSetMotorA(this->speedF, 2);
    }
}

void ArdCar::controllerTurnRight(char command){
    if (command != 'r') return; // Retorna imediatamente se o comando não for 'f'

    // Inicializa a velocidade se ainda não foi configurada
    if (this->speedR == 0) {
        this->speedR = 128;
    }

    // Atualiza a velocidade periodicamente
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        this->speedR = constrain(this->speedR + 1, 0, 255);

        bridge1.continuousSetMotorA(this->speedR, 1);
        bridge1.continuousSetMotorB(this->speedR, 1);
    }
}

void ArdCar::controllerTurnLeft(char command){
    if (command != 'l') return; // Retorna imediatamente se o comando não for 'f'

    // Inicializa a velocidade se ainda não foi configurada
    if (this->speedL == 0) {
        this->speedL = 128;
    }

    // Atualiza a velocidade periodicamente
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        this->speedL = constrain(this->speedL + 1, 0, 255);
        
        bridge1.continuousSetMotorB(this->speedL, 2);
        bridge2.continuousSetMotorA(this->speedL, 1);
    }
}

void ArdCar::controllerStopDirection(char command) {
    if (command != 'd') return; // Retorna imediatamente se o comando não for 'd'

    this->speedR = this->speedL = 0; // Reseta ambas as velocidades
    bridge1.continuousSetMotorA(0, 1);
    bridge2.continuousSetMotorA(0, 1);
    bridge1.continuousSetMotorB(0, 1);
    bridge1.continuousSetMotorB(0, 2);
}

void ArdCar::controllerStop(char command){
    if(command != 's') return;
    this->speedF = 0;
    bridge1.continuousSetMotorA(0, 1);
    bridge2.continuousSetMotorA(0, 1);
}

void ArdCar::controllerRotationRight(char command){
    if (command != 'R') return;

        // Inicializa a velocidade se ainda não foi configurada
    if (this->speedF == 0) {
        this->speedF = 128;
    }

    // Atualiza a velocidade periodicamente
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        this->speedF = constrain(this->speedF + 1, 0, 255);
       
        bridge1.continuousSetMotorA(this->speedF, 1);
        bridge1.continuousSetMotorB(this->speedF, 1);
        bridge2.continuousSetMotorA(this->speedF, 2);
    }
}

void ArdCar::controllerRotationLeft(char command){
    if (command != 'L') return;

        // Inicializa a velocidade se ainda não foi configurada
    if (this->speedF == 0) {
        this->speedF = 128;
    }

    // Atualiza a velocidade periodicamente
    if (millis() - this->lastUpdate >= 5) {
        this->lastUpdate = millis();
        this->speedF = constrain(this->speedF + 1, 0, 255);
        
        bridge1.continuousSetMotorA(this->speedF, 2);
        bridge1.continuousSetMotorB(this->speedF, 2);
        bridge2.continuousSetMotorA(this->speedF, 1);
    }
}

void ArdCar::controllerServAxisY(char command) {
    if (command != '+' && command != '-' && command != 'x') return; // Retorna imediatamente se o comando não for '+' ou '-'
    int angle = servY.read();
    
    if (command == '+') {
        if(millis() - lastUpdate >= 100){
            lastUpdate = millis();
            angle = constrain(angle + 10, 60, 180);
            servY.write(angle);
        }
    }

    if (command == '-') {
        if(millis() - lastUpdate >= 100){
            lastUpdate = millis();
            angle = constrain(angle -10, 60, 180);
            servY.write(angle);
        }
    }

    if (command == 'x') {
        if(millis() - lastUpdate >= 50){
            lastUpdate = millis();
            servY.write(angle);
        }
    }
}

void ArdCar::controllerServAttack(char command) {
    if (command != '1' && command != '2' && command != 'x') return; // Retorna imediatamente se o comando não for 'a' ou 'd'
    servMode = command;
    long passedTime = millis() - lastUpdate;

    if (command == '1') {
        if(passedTime >= 1000 && passedTime < 2000){
            servY.write(60);
        }
        if(passedTime >= 2000 && passedTime < 3000){
            servY.write(90);
        }
        if(passedTime >= 3000){
            lastUpdate = millis();
            servY.write(180);
        }
    }
}
