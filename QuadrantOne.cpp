#include "functions.h"

time_t pTime = 0; //Previous time
int pError = 0; //Previous error
double Kp = -0.005; //Coefficient for proportionality - adjustable
double Kd = -0.5; //Coefficient for derivative - adjustable

int MOTOR_LEFT = 1; //Left motor pin number
int MOTOR_RIGHT = 2; //Right motor pin number

unsigned char MOTOR_SPEED = 100;

int quadOne(){
    time_t cTime; //Current time
    int cError = get_error(); //Gets current error value
    time(&cTime); //Gets current time

    double dv = (double)(cError - pError) / (cTime - pTime); //Gets the derivative - I think?

    double motorAdjustment = cError * Kp + dv * Kd; //The final motor adjustment

   set_motor(MOTOR_LEFT, (char)(MOTOR_SPEED + motorAdjustment));
   set_motor(MOTOR_RIGHT, (char)(MOTOR_SPEED - motorAdjustment));

    //Something something change motor speeds

    pTime = cTime; //Assigns previous time to current time
    pError = cError; //Assigns previous error value to current error value
}
