//
// Created by Tim on 11/05/2018.
//

#include "functions.h"


clock_t pTime; //Previous time
int pError = 0; //Previous error
double Kp = 0.009; //Coefficient for proportionality - adjustable
double Kd = 0.0; //Coefficient for derivative - adjustable

int MOTOR_LEFT = 2; //Left motor pin number
int MOTOR_RIGHT = 1; //Right motor pin number

unsigned char MOTOR_SPEED = 55;

int quadOne(){
    clock_t cTime = clock(); //Current time
    int cError = get_error(); //Gets current error value


    double timeDifference = (double)(cTime - pTime) / CLOCKS_PER_SEC;

    double dv = (double)(cError - pError) / timeDifference; //Gets the derivative - I think?

    double motorAdjustment = cError * Kp + dv * Kd; //The final motor adjustment
    printf("motor adjustment : %f\n", motorAdjustment);

    set_motor(MOTOR_LEFT, (unsigned char)(MOTOR_SPEED + motorAdjustment));
    set_motor(MOTOR_RIGHT, (unsigned char)(MOTOR_SPEED - motorAdjustment));

    pTime = cTime; //Assigns previous time to current time
    pError = cError; //Assigns previous error value to current error value*/

    if((double)(clock() - sTime) / CLOCKS_PER_SEC > 2){
        set_motor(MOTOR_LEFT, 0);
        set_motor(MOTOR_RIGHT, 0);
        return 1;                   //Failsafe
    }
    return 0;
}
