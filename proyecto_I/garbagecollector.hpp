#ifndef GARBAGECOLLECTOR_HPP
#define GARBAGECOLLECTOR_HPP
#include <iostream>
#include "Lista.hpp"
#include "puntero.hpp"

using namespace std;


class GarbageCollector
{
public:

    GarbageCollector();
    void aumentarRef(int);
    int generarId();
    void eliminarPtr(Puntero*);
    void agregarPuntero(Puntero*);
    void verificar();
    void mostrarL();
    string enviarInfo();
private:
        Lista<Puntero*> direcciones;
        Lista<int> ids;
};

#endif // GARBAGECOLLECTOR_H
