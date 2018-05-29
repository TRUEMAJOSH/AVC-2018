//
// Created by Tim on 28/05/2018.
//

#include "functions.h"

/******************************/
/******REMOVE FAILSAFE*********/
/******************************/



int SENSOR_RIGHT = 0;
int SENSOR_CENTER = 1;
int SENSOR_LEFT = 2;

int rDistance = 5;


clock_t q4_pTime; //Previous time
double q4_pError = 0; //Previous error
double q4_Kp = 0.5;//0.35; //Coefficient for proportionality - adjustable
double q4_Kd = 0.0045; //Coefficient for derivative - adjustable

double adc_to_cm(int adc);

unsigned char q4_MOTOR_SPEED = 40;

int quadFour(){
    double cRight = adc_to_cm(read_analog(SENSOR_RIGHT));
    double cCenter = adc_to_cm(read_analog(SENSOR_CENTER));

    printf("center : %f\n", cCenter);

    if(detectRed()){
        set_motor(MOTOR_RIGHT, 0);
        set_motor(MOTOR_LEFT, 0);
        if(cCenter < 10){
            while(cCenter < 10){
                cCenter = adc_to_cm(read_analog(SENSOR_CENTER));
            }

            set_motor(MOTOR_LEFT, q4_MOTOR_SPEED);
            set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED);
            sleep1(1 ,0);

        }else{
            set_motor(MOTOR_LEFT, q4_MOTOR_SPEED);
            set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED);
            sleep1(1 ,0);
        }
    }else{
        if(cCenter < 8){
            while(cCenter < 8.5){
                cCenter = adc_to_cm(read_analog(SENSOR_CENTER));
                if(cRight < 10){
                    set_motor(MOTOR_LEFT, q4_MOTOR_SPEED - q4_MOTOR_SPEED/4);
                    set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED + q4_MOTOR_SPEED/2);
                }else{
                    set_motor(MOTOR_LEFT, q4_MOTOR_SPEED + q4_MOTOR_SPEED/2);
                    set_motor(MOTOR_RIGHT, q4_MOTOR_SPEED - q4_MOTOR_SPEED/4);
                }
            }
        }
    }

    clock_t q4_cTime = clock();

    double q4_cError = (rDistance - cRight);

    double timeDifference = (double)(q4_cTime - q4_pTime) / CLOCKS_PER_SEC;

    double dv = (q4_cError - q4_pError)/timeDifference;

    double motorAdjustment = q4_cError * q4_Kp + dv * q4_Kd;

    set_motor(MOTOR_LEFT, (unsigned char)(q4_MOTOR_SPEED - motorAdjustment));
    set_motor(MOTOR_RIGHT, (unsigned char)(q4_MOTOR_SPEED + motorAdjustment));

    q4_pTime = q4_cTime;
    q4_pError = q4_cError;

    return 0;
}


double adc_to_cm(int adc){
    return ((double)2914 / (adc + 5) - 1);
}