
#include "functions.h"

clock_t sTime;

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
                	return 0;
                	quadrant++;
                }
	            break;
	        case 3:
	            //Quadrant three code
	            break;
	        case 4:
	            //Quadrant four code
	            break;
	        default:
				//Finished the course!
	        	goto postLoop;
	    }
	}
	postLoop:
    return 0;
}
