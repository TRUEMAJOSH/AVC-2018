//
// Created by Tim on 11/05/2018.
//

#include "functions.h"


clock_t _pTime; //Previous time
int _pError = 0; //Previous error
double _Kp = 0.40;   //Coefficient for proportionality - adjustable
double _Kd = 0.0045;  //Coefficient for derivative - adjustable

unsigned char _MOTOR_SPEED = 37;


int quadThree(){
    clock_t cTime = clock(); //Current time
    int cError = get_error(); //Gets current error value

    if(cError == -15000){
        set_motor(MOTOR_LEFT, -(_MOTOR_SPEED + 10));
        set_motor(MOTOR_RIGHT, -_MOTOR_SPEED);
        sleep1(0,600000);
        return 0;
    }else if(cError == 15000){

        set_motor(MOTOR_LEFT, 0);
        set_motor(MOTOR_RIGHT, _MOTOR_SPEED);

        return 0;
    }



    double timeDifference = (double)(cTime - _pTime) / CLOCKS_PER_SEC;

    double dv = (double)(cError - _pError) / timeDifference; //Gets the derivative

    double motorAdjustment = cError * _Kp + dv * _Kd; //The final motor adjustment

    printf("motor_adjustment : %f\n", cError * _Kp + dv * _Kd);


    set_motor(MOTOR_LEFT, (unsigned char)(_MOTOR_SPEED + motorAdjustment));
    set_motor(MOTOR_RIGHT, (unsigned char)(_MOTOR_SPEED - motorAdjustment));

    _pTime = cTime; //Assigns previous time to current time
    _pError = cError; //Assigns previous error value to current error value*/

    return 0;
}

