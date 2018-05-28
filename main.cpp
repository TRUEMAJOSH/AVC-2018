
#include "functions.h"

clock_t sTime;

<<<<<<< HEAD
int ALL_BLACK = -10000;
int ALL_WHITE = 10000;
int WHITE_LEFT = -15000;
int WHITE_RIGHT = 15000;

int quadrant = 1;
=======
>>>>>>> parent of 9948b99... Somewhat working quad three code
int main() {
	init();
	int quadrant = 1;

	sTime = clock();

	while(true){
	    switch(quadrant){
	        case 1:
	        	if(quadOne()){
	        		quadrant++;
	        	}
	            break;
	        case 2:
                if(quadTwo()){
                	quadrant++;
                }
	            break;
	        case 3:
	            quadThree();
	            break;
	        case 4:
	            //Quadrant four code
	            break;
	        default:
				//Finished the course!
	        	goto postLoop;
	    }
<<<<<<< HEAD
=======

>>>>>>> parent of 9948b99... Somewhat working quad three code
        //Failsafe
        if((double)(clock() - sTime) / CLOCKS_PER_SEC > 10){
            set_motor(MOTOR_LEFT, 0);
            set_motor(MOTOR_RIGHT, 0);
            return 0;
        }
	}
	postLoop:
    return 0;
}
