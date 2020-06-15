/**
  * @file singleton.hpp
  * @author Sebastian Moya
  * @brief Plantilla de la clase Puntero
  */
#ifndef PUNTERO_HPP
#define PUNTERO_HPP
#include <iostream>
using namespace std;

/**
 * @brief The Puntero class clase encargada de definir la estructura de la clase VSPtrPointer, es la clase padre
 */
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
    virtual string infoPunt();
};

#endif // PUNTERO_HPP
