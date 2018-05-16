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


int get_error();
int quadOne();
int quadTwo();

extern clock_t sTime;

extern int MOTOR_LEFT;
extern int MOTOR_RIGHT;

extern unsigned char MOTOR_SPEED;

extern int min;
extern int max;


#endif //TEAM4AVC2018_FUNCTIONS_H
