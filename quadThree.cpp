//
<<<<<<< HEAD
// Created by Tim on 11/05/2018.
=======
// Created by Tim on 23/05/2018.
>>>>>>> 00517fb058454e8d671f5212e91751ce12c30a07
//
#include "functions.h"

<<<<<<< HEAD

clock_t _pTime; //Previous time
int _pError = 0; //Previous error
double _Kp = 0.40;   //Coefficient for proportionality - adjustable
double _Kd = 0.0045;  //Coefficient for derivative - adjustable

unsigned char _MOTOR_SPEED = 37;

=======
void turn_left();
void turn_right();
void turn_around();
bool turned_left = false;
>>>>>>> 00517fb058454e8d671f5212e91751ce12c30a07

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


<<<<<<< HEAD
    set_motor(MOTOR_LEFT, (unsigned char)(_MOTOR_SPEED + motorAdjustment));
    set_motor(MOTOR_RIGHT, (unsigned char)(_MOTOR_SPEED - motorAdjustment));

    _pTime = cTime; //Assigns previous time to current time
    _pError = cError; //Assigns previous error value to current error value*/

    return 0;
=======
    int error = get_error();
    if(error == -10000){
        set_motor(MOTOR_LEFT, 0);
        set_motor(MOTOR_RIGHT, 0);
        printf("returned all black");
        sleep1(1,0);
        if(!turned_left){
            turn_left();
            turned_left = true;
        }else{
            turn_around();
            turned_left = false;
        }
        return 0;
    }


    turned_left = false;
    set_motor(MOTOR_LEFT, MOTOR_SPEED);
    set_motor(MOTOR_RIGHT, MOTOR_SPEED);

    return 0;
}

void turn_left(){
    printf("Turning Left\n");

    set_motor(MOTOR_LEFT, -(MOTOR_SPEED + (MOTOR_SPEED/2)));
    set_motor(MOTOR_RIGHT, MOTOR_SPEED + (MOTOR_SPEED/2));

    sleep1(0,225000);

    set_motor(MOTOR_LEFT, 0);
    set_motor(MOTOR_RIGHT, 0);

    sleep1(1,0);
}

void turn_right(){
    printf("Turning Right\n");

    set_motor(MOTOR_LEFT, MOTOR_SPEED + (MOTOR_SPEED/2));
    set_motor(MOTOR_RIGHT, -(MOTOR_SPEED + (MOTOR_SPEED/2)));

    sleep1(0,250000);

    set_motor(MOTOR_LEFT, 0);
    set_motor(MOTOR_RIGHT, 0);
}

void turn_around(){

    printf("Turning Around\n");
    set_motor(MOTOR_LEFT, -(MOTOR_SPEED + (MOTOR_SPEED/2)));
    set_motor(MOTOR_RIGHT, (MOTOR_SPEED + (MOTOR_SPEED/2)));

    sleep1(0,400000);

    set_motor(MOTOR_LEFT, 0);
    set_motor(MOTOR_RIGHT, 0);
    sleep1(1,0);
>>>>>>> 00517fb058454e8d671f5212e91751ce12c30a07
}


