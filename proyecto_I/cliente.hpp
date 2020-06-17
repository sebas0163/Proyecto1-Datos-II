/** 
 * @file cliente.hpp 
 * @author Harold Espinoza
 * @version 1.5
 * @date 16/06/20
 * @brief Plantilla de la clase cliente con socket  
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

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

using namespace std;


/** 
 * @brief Clase Cliente encargada de manejar las funciones para la comunicacion con sockets 
 */
class Cliente{

    public:
        char msg[1500];
        int clientSd;
        int status;
        Cliente(int,string);
        int EnviarPwrd(string);
        void Enviar(string);
        void closeSocket();

};

#endif // CLIENTE_HPP
