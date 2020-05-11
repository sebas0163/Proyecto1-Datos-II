//#include <QCoreApplication>
#include "Lista.hpp"
#include <iostream>
#include "VSPtr.hpp"
#include "singleton.hpp"
#include "garbagecollector.hpp"
using namespace std;
int main(/*int argc, char *argv[]*/)
{
    VSPtr<int> puntero = VSPtr<int>::New();
    int p = 5;
   *puntero = p;
    //cout<<&puntero<<endl;
    //QCoreApplication a(argc, argv);
    return 0;
    //return a.exec();
}
