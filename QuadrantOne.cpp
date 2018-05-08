//
// Created by Tim on 9/05/2018.
//

#include <iostream>
#include "E101.h"

#include <chrono>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <time.h>;

int get_error();


time_t pTime = 0; //Previous time
int pError = 0; //Previous error
double Kp = 0.005; //Coefficient for proportionality
double Kd = 0.5; //Coefficient for derivative

int MOTOR_LEFT = 1; //Left motor pin number
int MOTOR_RIGHT = 2; //Right motor pin number

unsigned char MOTOR_SPEED = 100;

int quadOne(){
    time_t cTime; //Current time
    int cError = get_error(); //Gets current error value
    time(&cTime); //Gets current time

    double dE = (double)(cError - pError) / (cTime - pTime); //Gets the derivative - I think?

    //Something something change motor speeds


    double motorAdjustment = cError * Kp + dE * Kd; //The final motor adjustment

    pTime = cTime; //Assigns previous time to current time
    pError = cError; //Assigns previous error value to current error value
}
