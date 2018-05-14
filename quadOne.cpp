//
// Created by Tim on 13/05/2018.
//

#include "functions.h"

int quadOne(){
    char address[] = "";
    char message[] = "Please";
    int port = 1024;

    connect_to_server(address, port);
    send_to_server(message);
    receive_from_server(message);
    send_to_server(message);

    return 1;
}

