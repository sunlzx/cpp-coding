#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

#include "object.h"

class User:public Object
{
    int id;
    std::string name;

public:
    User();
    User(int id, std::string name);
    ~User();
    void show();

    virtual int hashCode();


//    Number& operator++ ();     // prefix ++: no parameter, returns a reference
//    Number  operator++ (int);  // postfix ++: dummy parameter, returns a value

    User& operator ++();// prefix ++
    User operator ++(int);// postfix ++

    User operator +(User);



};

#endif // USER_H
