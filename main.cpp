#include <iostream>
#include "E101.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>


int get_error();
bool open_gate();
int quadOne();


int main() {
	init();
	int quadrant = 0;

	while(true){
	    switch(quadrant){
	        case 0:
                quadOne();
	            break;
	        case 1:
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
                break;
	    }
	}
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



