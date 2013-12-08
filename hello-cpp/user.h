#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
    int id;
    std::string name;

public:
    User();
    User(int id, std::string name);
    ~User();
    void show();
};

#endif // USER_H
