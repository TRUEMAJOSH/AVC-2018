
#include "functions.h"

clock_t sTime;

int main() {
	init();
	int quadrant = 0;

	sTime = clock();

	while(true){
	    switch(quadrant){
	        case 0:
                if(quadOne()){
                	printf("test");
                    goto postLoop;
                }
	            break;
	        /*case 1:
	            //Quadrant two code
	            break;
	        case 2:
	            //Quadrant three code
	            break;
	        case 3:
	            //Quadrant four code
	            break;
	        default:
	            //Finished the course!
                break;*/
	    }
	}
	postLoop:
    return 0;
}
