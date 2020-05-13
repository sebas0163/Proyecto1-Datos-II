#ifndef VSPTR_HPP
#define VSPTR_HPP
#include "Lista.hpp"
#include <iostream>
#include "puntero.hpp"
#include "garbagecollector.hpp"
#include "singleton.hpp"

using namespace std;

template <typename T> class VSPtr : public Puntero{
public:
    VSPtr(){
        GarbageCollector* gc = Singleton::getInstancia();
        dato = new T;
        gc->agregarPuntero(this);
    }
    static VSPtr New(){
        return VSPtr();
    }
    void setData(T data){
        *dato = data;
    }
    VSPtr<T>& operator *(){
        return *this;
    }
    T operator &(){
        return *dato;
    }
    T* getDato(){
        return dato;
    }
    void operator =(VSPtr pointer){
        this->setId(pointer.getId());
        this->dato = pointer.getDato();
        cout<<"copie el id en el garbage y aumentê la referencia"<< endl;
        return;
    }
    void operator=(T data){
        if(sizeof (*dato)== sizeof(data)){
            setData(data);
        }else{
            cout<<"No es posible realizar la accion"<<endl;
        }
     }
    void destruir(){
        delete dato;
        cout<<"se ha destruido la referencia con exito"<<endl;
    }


private:
    T* dato;
};
#endif // VSPTR_H
