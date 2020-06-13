#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include "md5.h"
#include "md5.cpp"

using namespace std;

class Cliente{

    public:
        char msg[1500];
        int clientSd;
        int status;
        Cliente();
        void EnviarPwrd(string);
        void Enviar(string);
        void closeSocket();

};

Cliente::Cliente(){

    
    clientSd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sendSockAddr, peer_addr; 
    sendSockAddr.sin_family = AF_INET; 
    sendSockAddr.sin_addr.s_addr = INADDR_ANY;
    sendSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");    
    sendSockAddr.sin_port = 12345; 
    status = connect(clientSd,
                         (sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
    if(status < 0)
    {
        cout << "Error connecting to socket!" << endl; /*break;*/
    }
    


}

void Cliente::EnviarPwrd(string datos){

    memset(&msg, 0, sizeof(msg));
    strcpy(msg, md5(datos).c_str());
    send(clientSd, (char*)&msg, strlen(msg), 0);
    cout << "Awaiting server response..." << endl;
    memset(&msg, 0, sizeof(msg));//clear the buffer
    recv(clientSd, (char*)&msg, sizeof(msg), 0);
    cout << "respuesta: " << msg << endl;
    
}

void Cliente::Enviar(string datos){

    memset(&msg, 0, sizeof(msg));
    strcpy(msg, datos.c_str());
    send(clientSd, (char*)&msg, strlen(msg), 0);
    cout << "Awaiting server response..." << endl;
    memset(&msg, 0, sizeof(msg));//clear the buffer
    recv(clientSd, (char*)&msg, sizeof(msg), 0);
    cout << "respuesta: " << msg << endl;
    
}

void Cliente::closeSocket(){
    string datos = "exit";
    memset(&msg, 0, sizeof(msg));
    strcpy(msg, datos.c_str());
    send(clientSd, (char*)&msg, strlen(msg), 0);
    close(clientSd);
    cout << "socket cerrado"<<endl;

}