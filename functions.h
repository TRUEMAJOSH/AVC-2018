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
int detectRed();

int quadOne();
int quadTwo();
int quadThree();
int quadFour();

extern clock_t sTime;

extern int MOTOR_LEFT;
extern int MOTOR_RIGHT;


#endif //TEAM4AVC2018_FUNCTIONS_H
