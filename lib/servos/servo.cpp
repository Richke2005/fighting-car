#include "servo.h"


Servo::Servo(int *arg, bool data){
    this->arg = arg;
    this->data= data;
}

Servo::Servo(int *arg, int *position){
    this->arg = arg;
    this->position = position;
}

