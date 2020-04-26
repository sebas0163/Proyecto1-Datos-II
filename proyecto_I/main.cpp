#include <QCoreApplication>
#include "Lista.hpp"
#include <iostream>
#include "VSPtr.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    VSPtr<string> ptr = VSPtr<string>::New();
    VSPtr<string> ptr2 = VSPtr<string>::New();
    string p = "adios";
    ptr = ptr2;
    ptr = p;
    *ptr = "hola";
    cout<<*ptr<<endl;
    QCoreApplication a(argc, argv);
    return 0;

    return a.exec();
}
