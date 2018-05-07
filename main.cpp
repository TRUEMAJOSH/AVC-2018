#include <iostream>
#include "E101.h"


void process_image();


int main() {
	init();

	process_image();

    return 0;
}

void process_image(){
    take_picture();

    int min = 255;
    int max = 0;
    for(int x = 0; x < 320; x++){
        int pixel = get_pixel(120, x, 3);
        if(pixel > max){
            max = pixel;
        }                               //Gets the maximum and minimum brightness level across the center line
        if(pixel < min){
            min = pixel;
        }
    }


    int average_brightness = ((max-min)/2) + min; //Gets middle value of the brightness

    int error = 0;
    for(int x = 0; x < 320; x++){ //Scans the entire center row of the image
        int pixel = get_pixel(120, x, 3);
        // (pixels > average_brightness) will return 1 if the pixel is white or 0 of it's black
        // abs(x - 160) returns the absolute value of x - 160, this gives us the distance from the center meaning the very left most / right most pixel have the weight value of 159/160
        // * (x < 160) ? -1 : 1 means that if x is less than 160 everything will be multiplied by -1, otherwise by 1.
        error += (pixel > average_brightness) * (abs(x - 160)) * ((x < 160) ? -1 : 1);
    }


    printf("error : %d", error);
}

