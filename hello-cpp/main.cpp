#include <iostream>
#include <string>
#include <user.h>
#include <vector>

#include "animal.h"
#include "dog.h"

using namespace std;


namespace my {
    template <class T>
    T plus(T t1, T t2)
    {
        return t1 + t2;
    }
}

struct Car
{
    int cartId;
};

void test_template()
{

    cout<< my::plus<int>(1, 2) << endl;
    cout<< my::plus<double>(1.2, 2.2) << endl;
    cout<< my::plus<float>(1.2f, 1) << endl;
}


void test_class()
{
    User user(1, "lin");
    user.show();

    User *user2 = new User(26, "sunlzx");
    user2->show();
    delete user2;
    user2 = NULL;

    Dog dog;
    dog.show_name();

    Animal *a = new Dog();
    a->show_name();

    cout << sizeof(user) << endl;
    cout << sizeof(dog) << " " << sizeof(a) << endl;
    delete a;
}

void test_sizeof()
{
    cout << "int:" << sizeof(int) << " ";
    cout << "long:" << sizeof(long) << " ";
    cout << "long long:" << sizeof(long long) << " ";
    cout << "double:" << sizeof(double) << " ";
    cout << "long double:" << sizeof(long double) << " ";
    cout << endl;
}

void test_struct()
{
    struct Car car;
    car.cartId = 1;
    cout << car.cartId << endl;
}

void test_vector()
{
    vector<int> ids;
    int i;
    for(i = 0; i < 100; i++)
    {
        ids.push_back(i);
    }
    //
    cout <<  "size:" << ids.size() << endl;

    vector<int>::iterator iter1 = ids.begin();
    while(iter1 != ids.end()) {
        cout << *iter1 << " ";
        iter1 ++;
    }
    cout << endl;

    cout << "for" << endl;

    for(i =0; i < ids.size(); i++) {
        cout << ids[i] << " ";
    }
    cout << endl;

//    vector<int>::iterator iter1 = v.begin();
//     while( iter1 != v.end() && *iter1 % 2 != 0 ) {
//       iter1++;
//     }

}


int main()
{
    cout << "Hello World!" << endl;

//    test_template();
//    test_class();
//    test_sizeof();
//    test_struct();
    test_vector();

    return 0;
}

