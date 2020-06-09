#include "singleton.hpp"
/**
 * @brief Singleton::garbage incializa el garbage en nulo
 */
GarbageCollector* Singleton::garbage =0;
/**
 * @brief Singleton::getInstancia método que crea la instancia, sino la ha creado, y la retorna
 * @return
 */
GarbageCollector* Singleton::getInstancia(){
    if(garbage == 0 ){
        garbage = new GarbageCollector();
        //Aqui se le debe decir al socket de JS que se conecte.
    }
    return garbage;
}
