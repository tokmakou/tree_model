#ifndef OBJECT1_H
#define OBJECT1_H

#include <qrandom.h>

class Object1
{
public:
    Object1();

    int data1 = qrand();
    int data2 = qrand();
    int data3 = qrand();
};

#endif // OBJECT1_H
