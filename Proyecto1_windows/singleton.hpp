/**
  * @file singleton.hpp
  * @author Sebastian Moya
  * @brief Plantilla de la clase Singleton
  */
#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include "garbagecollector.hpp"

/**
 * @brief Clase encargada de verificar y manterner la unica instancia del GC.
 */
class Singleton
{
public:
    static GarbageCollector* garbage;
    Singleton();
    static GarbageCollector* getInstancia();
private:

};

#endif // SINGLETON_H
