#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include <iostream>

class Dog : public Animal
{
public:
    Dog();

    void show_name();

};

#endif // DOG_H
