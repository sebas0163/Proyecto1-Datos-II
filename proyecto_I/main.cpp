#include <QCoreApplication>
#include "Lista.hpp"
#include <iostream>
#include "VSPtr.hpp"
using namespace std;
int main(int argc, char *argv[])
{
    /*Lista<int> l1 =Lista<int>();
    l1.add(5);
    l1.add(8);
    l1.eliminar(0);
    cout<<l1.buscar(0).dato<<endl;*/
    GarbageCollector* gc = Singleton::getInstancia();
    VSPtr<int> puntero = VSPtr<int>::New();
    VSPtr<int> ptr = VSPtr<int>::New();
   *ptr = 8;
   *puntero = 4;
    gc->mostrarL();
    puntero.eliminarRef();
    gc->verificar();
    VSPtr<int> vs = VSPtr<int>::New();
    vs = 2;
    gc->mostrarL();
    //cout<<puntero.getId()<<endl;
    //cout<<ptr.getId()<<endl;
    QCoreApplication a(argc, argv);
    return 0;
    return a.exec();
}
