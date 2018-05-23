//
// Created by Tim on 15/05/2018.
//

#include "functions.h"


clock_t pTime; //Previous time
int pError = 0; //Previous error
double Kp = 0.40;   //Coefficient for proportionality - adjustable
double Kd = 0.005;  //Coefficient for derivative - adjustable

int MOTOR_LEFT = 2; //Left motor pin number
int MOTOR_RIGHT = 1; //Right motor pin number

unsigned char MOTOR_SPEED = 45; //Base motor speed


int quadThree(){
  clock_t cTime = clock(); //Current time
    int cError = get_error(); //Gets current error value

    if(cError == -10000){
        /* Code for loss of line */
        set_motor(MOTOR_RIGHT,-MOTOR_SPEED);
        set_motor(MOTOR_LEFT, -MOTOR_SPEED);
        sleep1(0,250000);
        printf("LOST LINE\n");
        return 0;
    }else if(cError == 10000){
        /* Code for detection of all white */
        set_motor(MOTOR_RIGHT,MOTOR_SPEED);
        set_motor(MOTOR_LEFT, 0);
        sleep1(0,500000);
        printf("ALL WHITE\n");
        return 1;
    }

    double timeDifference = (double)(cTime - pTime) / CLOCKS_PER_SEC;

    double dv = (double)(cError - pError) / timeDifference; //Gets the derivative

    double motorAdjustment = cError * Kp + dv * Kd; //The final motor adjustment

    set_motor(MOTOR_LEFT, (unsigned char)(MOTOR_SPEED + motorAdjustment));
    set_motor(MOTOR_RIGHT, (unsigned char)(MOTOR_SPEED - motorAdjustment));

    pTime = cTime; //Assigns previous time to current time
    pError = cError; //Assigns previous error value to current error value*/

    return 0;
}



}

