
#include "functions.h"

clock_t sTime;

int main() {
	init();
	int quadrant = 2;

	sTime = clock();

	while(true){
	    switch(quadrant){
	        case 1:
	            break;
	        case 2:
                if(quadTwo()){
                    printf("test");
                    goto postLoop;
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
                break;
	    }
	}
	postLoop:
    return 0;
}
