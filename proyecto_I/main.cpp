#include "Lista.hpp"
#include <iostream>
#include "VSPtr.hpp"
#include <unistd.h>
#include <thread>
using namespace std;

void prueba(){
    GarbageCollector* gc = Singleton::getInstancia();
    while(true){
        gc->ejecutarHilo();
        sleep(5);
    }
}

int main()
{
    thread p(prueba);
    VSPtr<int> puntero = VSPtr<int>::New();
    VSPtr<int> ptr = VSPtr<int>::New();
    VSPtr<float> str = VSPtr<float>::New();
    *str = 1.89;
   *ptr = 8;
   *puntero = 4;
    puntero.eliminarRef();
    VSPtr<int> vs = VSPtr<int>::New();
    vs = 2;
    p.join();
    //gc->mostrarL();
    //vs.obtener_data();
    //cout<<gc->enviarInfo()<<endl;
    //cout<<puntero.getId()<<endl;
    //cout<<ptr.getId()<<endl;
    return 0;

}
