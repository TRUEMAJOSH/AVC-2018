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
        }

        if(pixel < min){
            min = pixel;
        }
    }


    int average_brightness = ((max-min)/2) + min;

    int error = 0;
    for(int x = 0; x < 320; x++){
        int pixel = get_pixel(120, x, 3);

        error += (pixel > average_brightness) * (abs(x - 160)) * ((x < 160) ? -1 : 1);
    }


    printf("error : %d", error);
}

