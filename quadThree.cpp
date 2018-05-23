//
// Created by Tim on 23/05/2018.
//
#include "functions.h"

void turn_left();
void turn_right();
void turn_around();
bool allBlack = false;

int quadThree(){

    int error = get_error();
    if(error == -10000){
        set_motor(MOTOR_LEFT, 0);
        set_motor(MOTOR_RIGHT, 0);
        printf("returned all black");
        sleep1(1,0);
        allBlack = true
        if (allBlack){
            checkVert();
        }
        return 0;
    }


    turned_left = false;
    set_motor(MOTOR_LEFT, MOTOR_SPEED);
    set_motor(MOTOR_RIGHT, MOTOR_SPEED);

    return 0;
}

void checkVert(){   //checks vertically for anything left or right
    printf("Checking left & right");
    
    int np = 0;
    int error = 0;
    for(int y = 0; y < 240; y++){ //Scans the entire y axis of the image on the left side @ x = 20
        int pixel = get_pixel(y, 20, 3); //(y, x, 3)
        // (pixels > average_brightness) will return 1 if the pixel is white or 0 of it's black
        error += (pixel > average_brightness) * (x-160);
        if(pixel > average_brightness){ //turns left if white detected
            turn_left();
        }else if(pixel < average_brightness){
            for(int y = 0; y < 240; y++){ //Scans the entire y axis of the image on the right side @ x = 300
                int pixel = get_pixel(y, 300, 3); //(y, x, 3)
                // (pixels > average_brightness) will return 1 if the pixel is white or 0 of it's black
                error += (pixel > average_brightness) * (x-160);
                if(pixel > average_brightness){
                    turn_right();   //turns right if white detected
                }
            }
        }else {
            turn_around();
        }
    }
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
