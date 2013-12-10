#ifndef STATIC_CLASS_H
#define STATIC_CLASS_H

#include <iostream>

class StaticClass
{
public:
    static int counter;//声明静态数据成员
    StaticClass();

    static void show();
};

#endif // STATIC_CLASS_H
