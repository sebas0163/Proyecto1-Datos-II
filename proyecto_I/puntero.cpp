#include "puntero.hpp"
/**
 * @brief Puntero::Puntero constructor de la clase. inicializa el id en 0
 */
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

