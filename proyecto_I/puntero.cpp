#include "puntero.hpp"

Puntero::Puntero()
{
    id =0;
}
int Puntero::getId(){
    return id;
}
void Puntero::setId(int num){
    id = num;
}
bool Puntero::comprobar(){
    return true;
}
void Puntero::destruir(){

}
string Puntero::obtener_data(){
 cout<<"hola"<<endl;
}

