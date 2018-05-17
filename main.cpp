
#include "functions.h"

clock_t sTime; //Initial start time

int main() {
	init();
	int quadrant = 2;

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
	            goto postLoop;
	            //Quadrant three code
	            break;
	        case 4:
	            //Quadrant four code
	            break;
	        default:
				//Finished the course!
	        	goto postLoop;
	    }

        //Failsafe code
        if((double)(clock() - sTime) / CLOCKS_PER_SEC > 2.5){
            set_motor(MOTOR_LEFT, 0);
            set_motor(MOTOR_RIGHT, 0);
            return 0;
        }
	}
	postLoop:
    return 0;
}
