//
// Created by Tim on 11/05/2018.
//

#include "functions.h"


clock_t pTime; //Previous time
int pError = 0; //Previous error
double Kp = 0.40;//0.35; //Coefficient for proportionality - adjustable
double Kd = 0.005; //Coefficient for derivative - adjustable

int MOTOR_LEFT = 2; //Left motor pin number
int MOTOR_RIGHT = 1; //Right motor pin number

unsigned char MOTOR_SPEED = 45;

int quadTwo(){
    clock_t cTime = clock(); //Current time
    int cError = get_error(); //Gets current error value

    //printf("Error value : %d\n", cError);

    if(cError == -15000){
        set_motor(MOTOR_LEFT, -MOTOR_SPEED);
        set_motor(MOTOR_RIGHT, -MOTOR_SPEED);
        return 0;
    }else if(cError == 15000){
        set_motor(MOTOR_RIGHT, 0);
        set_motor(MOTOR_LEFT, 0);
        return 1;
    }

    double timeDifference = (double)(cTime - pTime) / CLOCKS_PER_SEC;

    double dv = (double)(cError - pError) / timeDifference; //Gets the derivative

    double motorAdjustment = cError * Kp + dv * Kd; //The final motor adjustment

    //printf("motor adjustment : %f\n", motorAdjustment);


    set_motor(MOTOR_LEFT, (unsigned char)(MOTOR_SPEED + motorAdjustment));
    set_motor(MOTOR_RIGHT, (unsigned char)(MOTOR_SPEED - motorAdjustment));

    pTime = cTime; //Assigns previous time to current time
    pError = cError; //Assigns previous error value to current error value*/
    //printf("Time elapsed : %f\n\n",(double)(clock() - sTime) / CLOCKS_PER_SEC);
    return 0;
}


