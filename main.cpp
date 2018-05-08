#include <iostream>
#include "E101.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>


void process_image();

bool open_gate();


int main() {
	init();

	process_image();

    return 0;
}

bool open_gate(){
    char ip[] = {'1','2','7','.','0','.','0','1'};
    int port = 0;

    connect_to_server(ip, port);

    char message[] = {'P','l','e','a','s','e'};     //Mock up gate network code
    send_to_server(message);

    receive_from_server(message);

    send_to_server(message);

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
        error += (pixel > average_brightness) * (std::abs(x - 160)) * ((x < 160) ? -1 : 1);
    }


    std::printf("error : %d", error);
}

