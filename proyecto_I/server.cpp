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
#include "jsoncpp/json/json.h"
#include "md5.h"
#include "md5.cpp"


using namespace std;

void bwrite(string user, int *puntero){

    ifstream ifs("LogServer.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); 
    ifs.close();
    obj["conexiones"]["Usuario"][*puntero] = user;

    Json::StyledWriter SW;
    ofstream OS;
    OS.open("LogServer.json");
    OS << SW.write(obj);
    OS.close();
    *puntero += 1;
    

}

void writedata(string data, int *puntero){

    ifstream ifs("ServerData.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); 
    ifs.close();
    obj["conexiones"]["Usuario"][*puntero-1] = data;

    Json::StyledWriter SW;
    ofstream OS;
    OS.open("ServerData.json");
    OS << SW.write(obj);
    OS.close();
    *puntero += 1;
    

}



//Server side
int main(int argc, char *argv[])
{
    //buffer to send and receive messages with
    char msg[1500];
     
    //setup a socket and connection tools
    
    struct sockaddr_in servAddr;
    int addrlen = sizeof(servAddr);
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = 12345;
 
    /*open stream oriented socket with internet address
    also keep track of the socket descriptor*/
    int serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSd < 0)
    {
        cerr << "Error establishing the server socket" << endl;
        exit(0);
    }
    //bind the socket to its local address
    int bindStatus = bind(serverSd, (struct sockaddr*) &servAddr, 
        sizeof(servAddr));
    if(bindStatus < 0)
    {
        cerr << "Error binding socket to local address" << endl;
        exit(0);
    }
    cout << "Waiting for a client to connect..." << endl;
    //listen for up to 5 requests at a time
    listen(serverSd, 5);
    
    //receive a request from client using accept
    //we need a new address to connect with the client
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);

    //accept, create a new socket descriptor to 
    //handle the new connection with client

    int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
    if(newSd < 0)
    {
        cerr << "Error accepting request from client!" << endl;
        exit(1);
    }


    cout << "Connected with client!" << endl;

    //lets keep track of the session time
    struct timeval start1, end1;
    gettimeofday(&start1, NULL);
    //also keep track of the amount of data sent as well

    string pswrd = md5("contra");
    
    int i = 0;
    int *contador = &i;

    int cpw = 0;

    int bytesRead, bytesWritten = 0;
    
    
    while(1)
    {

        cout << "Awaiting client response..." << endl;
        memset(&msg, 0, sizeof(msg)); //clear the buffer

        if (cpw == 0){
            bool B = true;
            while (B)
            {
            memset(&msg, 0, sizeof(msg));//clear the buffer
            bytesRead += recv(newSd, (char*)&msg, sizeof(msg), 0);
            if(!strcmp(msg, pswrd.c_str()))
            {
                    bwrite("usuario",contador);
                    B = false;
                    cpw = 1;
                    string data = "Correct";
                    memset(&msg, 0, sizeof(msg)); //clear the buffer
                    strcpy(msg, data.c_str());
                    send(newSd, (char*)&msg, strlen(msg), 0);
                    


            }else{
                    string data = "Incorrect";
                    memset(&msg, 0, sizeof(msg)); //clear the buffer
                    strcpy(msg, data.c_str());
                    send(newSd, (char*)&msg, strlen(msg), 0);

            }

            }           
             
        }
        memset(&msg, 0, sizeof(msg)); //clear the buffer
        bytesRead += recv(newSd, (char*)&msg, sizeof(msg), 0);

        if(!strcmp(msg, "exit"))
        {
            cout << "Client has quit the session" << endl;
            break;
        }
        writedata(msg,contador);
        cout << "Client: " << msg << endl;
        cout << ">";
        string data = "datos recibidos";
        //getline(cin, data);
        memset(&msg, 0, sizeof(msg)); //clear the buffer
        strcpy(msg, data.c_str());
        if(data == "exit")
        {
            //send to the client that server has closed the connection
            send(newSd, (char*)&msg, strlen(msg), 0);
            break;
        }
        //send the message to client
        bytesWritten += send(newSd, (char*)&msg, strlen(msg), 0);
        
    }
    //we need to close the socket descriptors after we're all done
    gettimeofday(&end1, NULL);
    close(newSd);
    close(serverSd);
    cout << "********Session********" << endl;
    cout << "Bytes written: " << bytesWritten << " Bytes read: " << bytesRead << endl;
    cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec) 
        << " secs" << endl;
    cout << "Connection closed..." << endl;
    
    return 0;   
}