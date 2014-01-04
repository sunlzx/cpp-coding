#ifndef MYTEST_H
#define MYTEST_H

#include <string>


using namespace std;

namespace mytest1 {

/**
 * @brief test_sizeof
 */
void test_sizeof()
{
    cout << "int:" << sizeof(int) << " ";
    cout << "long:" << sizeof(long) << " ";
    cout << "long long:" << sizeof(long long) << " ";
    cout << "double:" << sizeof(double) << " ";
    cout << "long double:" << sizeof(long double) << " ";
    cout << endl;
}

/**
 * @brief test_exec_cmd
 */
void test_exec_cmd()
{
    char *cmd = "sleep 100";
    char buf[10000];
    int status = mystd::exec_cmd(cmd, buf);
    cout << "exce cmd:" << cmd << endl;
    cout << "exce status:" << status << endl;
    cout << "result:" << buf << endl;

}



/**
 * @brief test_convert
 */
void test_convert()
{
    string a = "a";
    string b = "b";
    string c = a + b;
    int i = atoi("10"); //string2int
    char buf[10];
    sprintf(buf, "%d", i);//int2string
    cout << c + buf << endl;
    cout << c << i << endl;
}

/**
 * @brief test_algorithm
 */
void test_algorithm()
{
    cout<< std::max(1, 10)<< endl;

    int a = 1;
    int b = 2;
    std::swap(a, b);
    cout << "a:" << a << ",b:" << b << endl;

}




}

#include "static_class.h"

#include "animal.h"
#include "dog.h"
#include "user.h"
#include "object.h"

namespace test_class
{


void test_static_class()
{
    StaticClass::show();
    cout << StaticClass::counter << endl;
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


class User2:public Object
{
public:
    int hashCode()
    {
        return 1;
    }
};

void test_virtual_func()
{
    User *user = new User(26, "sunlzx");
    user->show();

//    *user++;

    User u(1, "test");
    u.show();

    (*user + u).show();

    u++;
    u.show();

    ++u;
    u.show();


    delete user;
    user = NULL;

    User2 user2;
    user2.hashCode();

}

void test_animal()
{
    Animal *a = new Dog();
    a->show_name();
    delete a;
}




}

namespace test_template
{

template <class T>
static
T plus(T t1, T t2)
{
    return t1 + t2;
}

void test_template()
{

    cout<< plus<int>(1, 2) << endl;
    cout<< plus<double>(1.2, 2.2) << endl;
    cout<< plus<float>(1.2f, 1) << endl;
}


}

namespace test_struct
{

struct Car
{
    int cartId;
};


void test_struct()
{
    struct Car car;
    car.cartId = 1;
    cout << car.cartId << endl;
}

}

#endif // MYTEST_H
