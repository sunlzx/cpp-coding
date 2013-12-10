#include "static_class.h"

int StaticClass::counter = 0;//定义并初始化静态数据成员

StaticClass::StaticClass()
{
}

void StaticClass::show()
{
    std::cout << "static method show()" << std::endl;
}
