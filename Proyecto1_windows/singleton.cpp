#include "singleton.hpp"

GarbageCollector* Singleton::garbage =0;
GarbageCollector* Singleton::getInstancia(){
    if(garbage == 0 ){
        garbage = new GarbageCollector();
    }
    return garbage;
}
