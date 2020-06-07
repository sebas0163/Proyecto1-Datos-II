#ifndef PUNTERO_HPP
#define PUNTERO_HPP
#include <iostream>
using namespace std;


class Puntero
{
public:
    int id;
    Puntero();
    void setId(int);
    int getId();
    virtual bool comprobar();
    virtual void destruir();
    virtual string obtener_data();
};

#endif // PUNTERO_HPP
