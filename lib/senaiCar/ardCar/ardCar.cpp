#include "./ardCar.hpp"

ArdCar::ArdCar() : Car() {};

void ArdCar::controllerForward(const char * const command, SoftwareSerial* response){
    if(*command == 'f'){
        refreshSpeed(command);

        int dirMA = bridge1.continuousSetMotorA(speedL, 1);
        int dirMB = bridge2.continuousSetMotorA(speedR, 1);

        if(dirMA == 0 || dirMB == 0){
            //response->println("motors are off");
        }
        //response->println("motor A is on, port: " + (String) dirMA);
        //response->println("motor B is on, port: " + (String) dirMB);
    }
}

void ArdCar::controllerBackward(const char * const command, SoftwareSerial* response){
    if(*command == 'b'){
        refreshSpeed(command);

        int dirMA = bridge1.continuousSetMotorA(speedL, 2);
        int dirMB = bridge2.continuousSetMotorA(speedR, 2);

        if(dirMA == 0 || dirMB == 0){
            //response->println("motors are off");
        }
        //response->println("motor A is on, port: " + (String) dirMA);
        //response->println("motor B is on, port: " + (String) dirMB);
    }
}

void ArdCar::controllerTurnRight(const char * const command, SoftwareSerial* response){
    if(*command == 'r'){
        refreshSpeed(command);

        int dirMA = bridge1.continuousSetMotorB(speedF, 1);

        (void) dirMA;

        //if(dirMA == 0)
            //response->println("motors are off");
        
        //response->println("motor A is on, port: " + (String) dirMA);
    }
}

void ArdCar::controllerTurnLeft(const char * const command, SoftwareSerial* response){
    if(*command == 'l'){

        refreshSpeed(command);

        int dirMA = bridge1.continuousSetMotorB(speedF, 2);

        (void) dirMA;

        //if(dirMA == 0)
            //response->println("motors are off");
        
        //response->println("motor A is on, port: " + (String) dirMA);
    }
}

void ArdCar::controllerStopDirection(const char * const command, SoftwareSerial* response){
    if(*command == 'd'){
        refreshSpeed(command);
        bridge1.continuousSetMotorB(speedF, 1);
        //bridge1.continuousSetMotorB(LOW, 2);
        //response->println("Direction is off");
    }
}

void ArdCar::controllerStop(const char * const command, SoftwareSerial* response){
    if(*command == 's'){
        refreshSpeed(command);
        bridge1.continuousSetMotorA(speedL, 1);
        bridge2.continuousSetMotorA(speedR, 1);
        //bridge1.continuousSetMotorB(LOW, 2);
        //bridge2.continuousSetMotorA(LOW, 2);
        //response->println("motors are off");
    }
}

void ArdCar::rotationRight(const char * const command, SoftwareSerial* response){
    if(*command == 'R'){
        refreshSpeed(command);
        bridge1.continuousSetMotorA(speedL, 1);
        bridge1.continuousSetMotorB(speedF, 1);
        bridge2.continuousSetMotorA(speedR, 2);

        //response->println("motors are on");
    }
}

void ArdCar::rotationLeft(const char * const command, SoftwareSerial* response){
    if(*command == 'L'){
        refreshSpeed(command);
        bridge1.continuousSetMotorA(speedL, 2);
        bridge1.continuousSetMotorB(speedF, 2);
        bridge2.continuousSetMotorA(speedR, 1);

        //response->println("motors are on");
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

void ArdCar::controllerServAxisY(const char * const command, SoftwareSerial* response){
    if(*command == '-'){
        int angle = servY.read();
        servY.write(angle - 27);
        
    }

    if(*command == '+'){
        int angle = servY.read();
        servY.write(angle + 27);
    }
}