//
// Created by Tim on 28/05/2018.
//

#include "functions.h"

/******************************/
/******REMOVE FAILSAFE*********/
/******************************/



int SENSOR_RIGHT = 0;
int SENSOR_CENTER = 1;

int rDistance = 5.5;


clock_t q4_pTime; //Previous time
double q4_pError = 0; //Previous error
double q4_Kp = 1;//0.35; //Coefficient for proportionality - adjustable
double q4_Kd = 0.6; //Coefficient for derivative - adjustable

double adc_to_cm(int adc);

unsigned char q4_MOTOR_SPEED = 35;

int quadFour(){
    double cRight = adc_to_cm(read_analog(SENSOR_RIGHT));
    double cCenter = adc_to_cm(read_analog(SENSOR_CENTER));

    printf("center : %f\n", cCenter);
    printf("right : %f\n\n", cRight);



    if(detectRed()){
        set_motor(MOTOR_RIGHT, 0);
        set_motor(MOTOR_LEFT, 0);

        if(cCenter < 30){
            while(cCenter < 30){
                cCenter = adc_to_cm(read_analog(SENSOR_CENTER));
            }

            while(detectRed()) {
                set_motor(MOTOR_LEFT, q4_MOTOR_SPEED);
                set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED);
            }

        }else{

            while(detectRed()){
                set_motor(MOTOR_LEFT, q4_MOTOR_SPEED);
                set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED);
            }
        }

    }

    while(cCenter < 23 && cCenter > 7){
        cCenter = adc_to_cm(read_analog(SENSOR_CENTER));
        set_motor(MOTOR_LEFT, q4_MOTOR_SPEED);
        set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED);
    }


    if(cCenter <= 6.5){
        cRight = adc_to_cm(read_analog(SENSOR_RIGHT));
        if(cRight < 25){
            while(cCenter < 15){
                cCenter = adc_to_cm(read_analog(SENSOR_CENTER));
                set_motor(MOTOR_LEFT, 0);
                set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED*1.5);
            }
        }else{
            while(cCenter < 16){
                cCenter = adc_to_cm(read_analog(SENSOR_CENTER));
                set_motor(MOTOR_RIGHT, 0);
                set_motor(MOTOR_LEFT, q4_MOTOR_SPEED*1.5);

            }
        }
        return 0;
    }


    clock_t q4_cTime = clock();

    double q4_cError = (rDistance - cRight);

    printf("q4_error : %f\n", q4_cError);

    double timeDifference = (double)(q4_cTime - q4_pTime) / CLOCKS_PER_SEC;

    double dv = (q4_cError - q4_pError)/timeDifference;

    double motorAdjustment = q4_cError * q4_Kp + dv * q4_Kd;

    printf("MOTOR ADJUSTMENT : %f\n", motorAdjustment);


    set_motor(MOTOR_LEFT, (unsigned char)(q4_MOTOR_SPEED - motorAdjustment));
    set_motor(MOTOR_RIGHT, (unsigned char)(q4_MOTOR_SPEED + motorAdjustment));

    q4_pTime = q4_cTime;
    q4_pError = q4_cError;

    return 0;
}


double adc_to_cm(int adc){
    return ((double)2914 / (adc + 5) - 1);
}