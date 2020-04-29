#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include "garbagecollector.hpp"


class Singleton
{
public:
    static GarbageCollector* garbage;
    Singleton();
    static GarbageCollector* getInstancia();
private:

};

#endif // SINGLETON_H
