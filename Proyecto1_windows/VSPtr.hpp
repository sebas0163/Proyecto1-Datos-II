#ifndef VSPTR_HPP
#define VSPTR_HPP
#include "Lista.hpp"
#include <iostream>

using namespace std;

template <typename T> class VSPtr{
public:
    VSPtr(){
        id = 0;
        ref=1;
    }
    void setId(int ID){
        id = ID;
    }
    void setRef(int re){
        ref = re;
    }
    int getId(){
        return id;
    }
    int getRef(){
        return ref;
    }
    static VSPtr New(){
        return VSPtr();
    }
    void setDta(T data){
        dato = data;
    }
    T operator *(){
        return dato;
    }
    T operator &(){
        return *dato;
    }
    void operator =(VSPtr pointer){
        this->setId(pointer.getId());
        cout<<"copie el id en el garbage y aumentê la referencia"<< endl;
        return;
    }
    void operator=(T data){
        if(sizeof (dato)== sizeof(data)){
            dato = data;
        }else{
            cout<<"No es posible realizar la accion"<<endl;
        }
     }
    void destruir(){
        cout<<"se ha destruido con exito"<<endl;
    }

private:
    T dato;
    int memory;
    int id;
    int ref;
};
#endif // VSPTR_H
