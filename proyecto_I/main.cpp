#include <QCoreApplication>
#include "Lista.hpp"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    Lista<int> l1;
    l1.add(2);
    l1.add(50);
    l1.add(40);
    l1.add(85);
    l1.print();
    //cout<<l1.largo<<endl;
    QCoreApplication a(argc, argv);
    return 0;

    return a.exec();
}
