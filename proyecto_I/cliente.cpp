/** 
 * @file cliente.cpp
 * @author Harold Espinoza 
 * @brief Definicion de las funciones de la clase cliente 
 * @version 1.8
 * @date 16/06/20  
 * */

#include "cliente.hpp"

/** 
 * @brief Cliente::Cliente constructor para la clase cliente que inicia la conexion con el server
 */
Cliente::Cliente(int puerto, string ip){

    
    clientSd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sendSockAddr, peer_addr; 
    sendSockAddr.sin_family = AF_INET; 
    sendSockAddr.sin_addr.s_addr = INADDR_ANY;
    sendSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sendSockAddr.sin_port = puerto; 
    status = connect(clientSd,
                         (sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
    if(status < 0)
    {
        cout << "Error connecting to socket!" << endl; /*break;*/
    }
    


}

/** 
 * @brief Cliente::EnviarPwrd Funcion encargada de enviar la contraseña al servidor 
 * @param datos Recibe la contraseña ingresada por el usuario
 * @return Regresa un entero 1 si la contraseña es erronea o un 0 si la contraseña es correcta
 */

int Cliente::EnviarPwrd(string datos){
    memset(&msg, 0, sizeof(msg));
    strcpy(msg, datos.c_str());
    send(clientSd, (char*)&msg, strlen(msg), 0);
    cout << "Awaiting server response..." << endl;
    memset(&msg, 0, sizeof(msg));//clear the buffer
    recv(clientSd, (char*)&msg, sizeof(msg), 0);
    cout << "respuesta: " << msg << endl;
    if (!strcmp(msg, "Incorrect")){
        return 1;
    }else
    {
        return 0;
    }
    
    
}

/** 
 * @brief Cliente::EnviarPwrd Funcion encargada de enviar los datos al servidor 
 * @param datos Recibe los datos que se deben enviar al servidor
 * 
 */

void Cliente::Enviar(string datos){
    memset(&msg, 0, sizeof(msg));
    strcpy(msg, datos.c_str());
    send(clientSd, (char*)&msg, strlen(msg), 0);
    cout << "Awaiting server response..." << endl;
    memset(&msg, 0, sizeof(msg));//clear the buffer
    recv(clientSd, (char*)&msg, sizeof(msg), 0);
    cout << "respuesta: " << msg << endl;
    
}

/** 
 * @brief Cliente::closeSocket Funcion que cierra la conexion con el servidor 
 */

void Cliente::closeSocket(){
    string datos = "exit";
    memset(&msg, 0, sizeof(msg));
    strcpy(msg, datos.c_str());
    send(clientSd, (char*)&msg, strlen(msg), 0);
    close(clientSd);
    cout << "socket cerrado"<<endl;

}
