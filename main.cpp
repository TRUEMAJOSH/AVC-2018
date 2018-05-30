
#include "functions.h"

clock_t sTime;

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
	            if(quadThree()){
	                quadrant++;
	            }
	            break;
	        case 4:
	            quadrant += quadFour();
	            break;
	        default:
				//Finished the course!
	        	goto postLoop;
	    }
	}
	postLoop:
    return 0;
}
