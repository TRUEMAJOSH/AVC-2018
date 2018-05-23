//
// Created by Tim on 10/05/2018.
//

#ifndef TEAM4AVC2018_FUNCTIONS_H
#define TEAM4AVC2018_FUNCTIONS_H


#include <iostream>
#include "E101.h"

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <sys/time.h>
/* Functions */
int get_error();
//int get_q3_error();
int quadOne();
int quadTwo();
int quadThree();

/* Global Variables */
extern clock_t sTime;

extern int whitePixels;
extern int counter;
extern int averagePixels;

extern int MOTOR_LEFT;
extern int MOTOR_RIGHT;

extern unsigned char MOTOR_SPEED;

extern int quadrant;

extern int ALL_WHITE;
extern int ALL_BLACK;
extern int WHITE_LEFT;
extern int WHITE_RIGHT;

#endif //TEAM4AVC2018_FUNCTIONS_H
