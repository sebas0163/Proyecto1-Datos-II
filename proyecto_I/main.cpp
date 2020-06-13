#include <QCoreApplication>
#include "Lista.hpp"
#include <iostream>
#include "VSPtr.hpp"
using namespace std;
int main(int argc, char *argv[])
{
    GarbageCollector* gc = Singleton::getInstancia();
    VSPtr<int> puntero = VSPtr<int>::New();
    VSPtr<int> ptr = VSPtr<int>::New();
    VSPtr<float> str = VSPtr<float>::New();
    *str = 1.89;
   *ptr = 8;
   *puntero = 4;
    gc->ejecutarHilo();
    puntero.eliminarRef();
    gc->ejecutarHilo();
    VSPtr<int> vs = VSPtr<int>::New();
    vs = 2;
    //gc->mostrarL();
    //vs.obtener_data();
    //cout<<gc->enviarInfo()<<endl;
    //cout<<puntero.getId()<<endl;
    //cout<<ptr.getId()<<endl;
    QCoreApplication a(argc, argv);
    return 0;
    return a.exec();
}
