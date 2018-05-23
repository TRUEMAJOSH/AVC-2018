//
// Created by Tim on 23/05/2018.
//
#include "functions.h"

void turn_left();
void turn_right();
void turn_around();
bool turned_left = false;

int quadThree(){

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
}


