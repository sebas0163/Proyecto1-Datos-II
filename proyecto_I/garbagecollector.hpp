#ifndef GARBAGECOLLECTOR_HPP
#define GARBAGECOLLECTOR_HPP
#include <iostream>
#include "Lista.hpp"
#include "puntero.hpp"
#include "cliente.hpp"
#include <fstream>
/**
 *@file garbagecollector.hpp
 * @author Sebastián moya
 * @brief Clase plantilla para el garbage collector
 */
using namespace std;

/**
 * @brief The GarbageCollector class clase encargada de guardar los punteros creados
 */
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
    string infoPunts();
    void ejecutarHilo();
private:
        string informacion;
        Lista<Puntero*> direcciones;
        Lista<int> ids;
};

#endif // GARBAGECOLLECTOR_H
