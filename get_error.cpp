#include "functions.h"


int BLACK_THRESHOLD = 100;
int WHITE_THRESHOLD = 100;

int get_error(){
    take_picture();

    int BLACK_THRESHOLD = 50;//50;   //Threshold for detecting all black - adjustable - change to dynamically changed?
    int WHITE_THRESHOLD = 110;//145;  //Threshold for detecting all white - adjustable - change to dynamically changed?

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

    int average_brightness = ((max-min)/2) + min;

<<<<<<< HEAD
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
=======
    if(average_brightness < BLACK_THRESHOLD){
        printf("average_brightness : %d\n", average_brightness);
        printf("Returned all black\n");
        return -10000;                                             //Returns -10000 when detected all black
    }else if(average_brightness > WHITE_THRESHOLD){
        printf("average_brightness : %d\n", average_brightness);
        printf("Returned all white\n");
        return ALL_WHITE;                                              //Returns 10000 when detected all white
    }
>>>>>>> 00517fb058454e8d671f5212e91751ce12c30a07

    printf("average_brightness : %d\n", average_brightness);
    printf("Returned line\n");

    int np = 0;
    int error = 0;
    for(int x = 0; x < 320; x++){ //Scans the entire center row of the image
        int pixel = get_pixel(120, x, 3);
        // (pixels > average_brightness) will return 1 if the pixel is white or 0 of it's black
        if(pixel > average_brightness) {
            error += x-160;
            np++;
        }

    }


    whitePixels += np;
    counter++;

    error /= np; //Sets error to error value divided by number of white pixels detected

    return error;
}
