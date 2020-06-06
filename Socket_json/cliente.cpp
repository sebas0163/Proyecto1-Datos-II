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
//Client side
int main(int argc, char *argv[])
{
    //we need 2 things: ip address and port number, in that order
    
    //create a message buffer 
    
    char msg[1500]; 
    //setup a socket and connection tools 
    //struct hostent* host = gethostbyname(serverIp);
    

    int clientSd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sendSockAddr, peer_addr; 
    sendSockAddr.sin_family = AF_INET; 
    sendSockAddr.sin_addr.s_addr = INADDR_ANY; 
      
    // This ip address will change according to the machine 
    sendSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
      
    sendSockAddr.sin_port = 12345; 

    //try to connect...
    int status = connect(clientSd,
                         (sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
    if(status < 0)
    {
        cout<<"Error connecting to socket!"<<endl; /*break;*/
    }
    cout << "Ingrese la contrasenia" << endl;

    /*string data;
    getline(cin, data);
    
    memset(&msg, 0, sizeof(msg));//clear the buffer
    strcpy(msg, md5(data).c_str());*/


    int bytesRead, bytesWritten = 0;
    struct timeval start1, end1;
    gettimeofday(&start1, NULL);
    int init = 0;
    while(1)
    {
        
        cout << ">";
        string data;
        getline(cin, data);
        if(init == 0 ){
            memset(&msg, 0, sizeof(msg));//clear the buffer
            strcpy(msg, md5(data).c_str());
            init = 1;
        }else{
            memset(&msg, 0, sizeof(msg));//clear the buffer
            strcpy(msg, data.c_str());  
        }
        
        if(data == "exit")
        {
            send(clientSd, (char*)&msg, strlen(msg), 0);
            break;
        }
        bytesWritten += send(clientSd, (char*)&msg, strlen(msg), 0);
        cout << "Awaiting server response..." << endl;
        memset(&msg, 0, sizeof(msg));//clear the buffer
        bytesRead += recv(clientSd, (char*)&msg, sizeof(msg), 0);
        cout << "respuesta: " << msg << endl;
        if(!strcmp(msg, "exit"))
        {
            cout << "Server has quit the session" << endl;
            break;
        
        }
        
        if(!strcmp(msg, "Incorrect"))
        {
            init = 0;
            cout << "Entro al if de incorrect" << endl;
        }
        cout << "Server: " << msg << endl;
    }
    gettimeofday(&end1, NULL);
    close(clientSd);
    cout << "********Session********" << endl;
    cout << "Bytes written: " << bytesWritten << 
    " Bytes read: " << bytesRead << endl;
    cout << "Elapsed time: " << (end1.tv_sec- start1.tv_sec) 
      << " secs" << endl;
    cout << "Connection closed" << endl;
    return 0;    
}