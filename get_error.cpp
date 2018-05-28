#include "functions.h"


int BLACK_THRESHOLD = 100;
int WHITE_THRESHOLD = 100;

int get_error(){
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


    printf("max_brightness : %d\n", max);
    int average_brightness = ((max-min)/2) + min; //Gets mid point of brightness

    if(max < BLACK_THRESHOLD){
        printf("average : %d\n", average_brightness);
        printf("Returned all black\n");
        return -15000;                                             //Returns -15000 when detected all black
    }else if(min > WHITE_THRESHOLD){
        printf("average : %d\n", average_brightness);
        printf("Returned all white\n");
        return 15000;                                              //Returns 15000 when detected all white
    }
    printf("Returned line");


    int np = 0;
    int error = 0;
    for(int x = 0; x < 320; x++){ //Scans the entire center row of the image
        int pixel = get_pixel(120, x, 3);
        // (pixels > average_brightness) will return 1 if the pixel is white or 0 of it's black
        error += (pixel > average_brightness) * (x-160);
        if(pixel > average_brightness)
            np++;
    }

    if(np == 0){
        return 0;
    }
    printf("average_brightness %d\n", average_brightness);
    printf("Error_value : %d\n", error);

    error /= np;
    printf("adjusted_error : %d\n\n\n",error);

    return error;
}
