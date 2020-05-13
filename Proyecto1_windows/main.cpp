//#include <QCoreApplication>
#include "Lista.hpp"
#include <iostream>
#include "VSPtr.hpp"
#include "singleton.hpp"
#include "garbagecollector.hpp"
using namespace std;
int main(/*int argc, char *argv[]*/)
{
    GarbageCollector* gc = Singleton::getInstancia();
    VSPtr<int> puntero = VSPtr<int>::New();
    VSPtr<int> ptr = VSPtr<int>::New();
   *ptr = 8;
   *puntero = 4;
    puntero = ptr;
    cout<<&puntero<<endl;
    cout<<&ptr<<endl;
    //QCoreApplication a(argc, argv);
    return 0;
    //return a.exec();
}
