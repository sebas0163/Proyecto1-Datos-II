#include <iostream>
#include <winsock2.h>

using namespace std;

class Client{
public:
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
    char buffer[1024];
    bool Run = TRUE;
    Client()
    {
        cout<<"Conectando al servidor..."<<endl<<endl;
        WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_addr.s_addr = inet_addr("192.168.1.14");
        addr.sin_family = AF_INET;
        addr.sin_port = htons(5555);
        int status = connect(server, (SOCKADDR *)&addr, sizeof(addr));
        
        if(status < 0)
        {
            cout<<"Error connecting to socket!"<<endl;
            this->Run=FALSE;
            
        }else{
        cout << "Conectado al Servidor!" << endl;
        }
    }
    void Enviar()
    {
        cout<<"Escribe el mensaje a enviar: ";
        cin>>this->buffer;
        //cout<<"mensaje enviado: " <<this->buffer<<endl;
        string str (this->buffer);
        if(str != "close")
        {
            //cout<<"comparacion: " <<"diferente" << endl;
            send(server, buffer, sizeof(buffer), 0);           
            memset(buffer, 0, sizeof(buffer));
            cout << "Mensaje enviado!" << endl;
        }else{
            send(server, buffer, sizeof(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
            this->CerrarSocket();
            
        }
            
    }
    void Recibir()
    {
        if(this->Run==TRUE)
        {
            recv(server, buffer, sizeof(buffer), 0);
            cout << "El servidor dice: " << buffer << endl;
            memset(buffer, 0, sizeof(buffer));
        }
        
    }
    void CerrarSocket()
    {
       closesocket(server);
       WSACleanup();
       Run = FALSE;
       cout << "Socket cerrado." << endl << endl;
    }
};

int main()
{
    Client *Cliente = new Client();
    //Cliente->Run=TRUE;
    while(Cliente->Run==TRUE)
    {
        Cliente->Enviar();
        Cliente->Recibir();
    }
}