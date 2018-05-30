//
// Created by Tim on 28/05/2018.
//

#include "functions.h"

int detectRed(){
    take_picture();

    int averageRed = 0;
    int averageGreen = 0;
    int averageBlue = 0;

    for(int x = 0; x < 320; x++){
        averageRed += get_pixel(120, x, 0);
        averageGreen += get_pixel(120, x, 1);
        averageBlue += get_pixel(120, x, 2);
    }

    averageRed /= 320;
    averageBlue /= 320;
    averageGreen /= 320;

    printf("red : %d\ngreen : %d\nblue : %d\n\n", averageRed, averageGreen, averageBlue);

    return averageRed > 100 && averageBlue < 100 && averageGreen < 100;
}