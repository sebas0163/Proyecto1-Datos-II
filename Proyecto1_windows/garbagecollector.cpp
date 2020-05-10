#include "garbagecollector.hpp"


GarbageCollector::GarbageCollector()
{
    direcciones = Lista<int>();
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
void GarbageCollector::agregarPuntero(int ptr){
    direcciones.add(ptr);
}
void GarbageCollector::aumentarRef(int direc){

}
