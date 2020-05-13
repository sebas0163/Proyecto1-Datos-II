#include <QCoreApplication>
#include "Lista.hpp"
#include <iostream>
#include "VSPtr.hpp"
using namespace std;
int main(int argc, char *argv[])
{
    VSPtr<int> puntero = VSPtr<int>::New();
    VSPtr<int> ptr = VSPtr<int>::New();
   *ptr = 8;
   *puntero = 4;
    //puntero = ptr;
    cout<<puntero.getId()<<endl;
    cout<<ptr.getId()<<endl;
    QCoreApplication a(argc, argv);
    return 0;
    return a.exec();
}
