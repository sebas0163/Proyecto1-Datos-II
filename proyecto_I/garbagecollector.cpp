#include "garbagecollector.hpp"


GarbageCollector::GarbageCollector()
{
    direcciones = Lista<Puntero*>();
    ids = Lista<int>();
}
int GarbageCollector::generarId(){
    int id = 1;
    for(int i =1; i<1000;i++){
        if(ids.verificar(i)){
           id ++;
        }else{
            break;
        }
    }
    ids.add(id);
    return id;
}
void GarbageCollector::agregarPuntero(Puntero* ptr){
    direcciones.add(ptr);
    ptr->setId(generarId());
}
void GarbageCollector::verificar(){
    int i = 0;
    while (i<direcciones.largo){
        if(direcciones.buscar(i).dato->comprobar()){
            direcciones.buscar(i).dato->destruir();
            delete direcciones.buscar(i).dato;
            direcciones.eliminar(i);
            ids.eliminar(i);
            cout<<"aui estoy"<<endl;
        }else{
            i++;
        }
    }
}
void GarbageCollector::mostrarL(){
    for (int i =0; i<direcciones.largo;i++){
        cout<<direcciones.buscar(i).dato->getId()<<endl;
    }
}
