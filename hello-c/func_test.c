#include "func_test.h"

#include <stdio.h>

static
int add(int a, int b)
{
    return a + b;
}

typedef int add_f(int a, int b);

static
int add2(add_f *add_f, int a, int b)
{
    return add_f(a, b);
}

static
int add3(add_f add_f, int a, int b)
{
    return add_f(a, b);
}



void test_func_pointer()
{
    printf("%d\n", add(1, 0));
    printf("%d\n", add2(add, 2, 0));
    printf("%d\n", add3(*add, 3, 0));

    typedef int (*add_f)(int a, int b);
    add_f func1;
    func1 = add;
    printf("%d\n", func1(6, 0));

    typedef int (add_f2)(int a, int b);
    add_f2 *func2;
    func2 = add;
    printf("%d\n", func2(7, 0));

}
