#ifndef GARBAGECOLLECTOR_HPP
#define GARBAGECOLLECTOR_HPP
#include <iostream>
#include "Lista.hpp"
#include "VSPtr.hpp"

using namespace std;


class GarbageCollector
{
public:

    GarbageCollector();
    void aumentarRef(int);
    int generarId();
    void eliminarPtr(int);
    void agregarPuntero(int);
private:
        Lista<int> direcciones;
        Lista<int> ids;
};

#endif // GARBAGECOLLECTOR_H
