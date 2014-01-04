#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "epoll_test.h"
#include "func_test.h"
#include "longjmp_test.h"

#define ADD(x, y) ({int _z = x + y; _z;})

#define test(x, y) ({   \
    int _z = x + y;     \
    _z; })



void test_bit_field()
{

    typedef struct bs
    {
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    }s_bs,*pbs;

    s_bs bs1;
    pbs pbs1;
    bs1.a = 1;
    bs1.b = 7;
    bs1.c = 15;
    printf("%d,%d,%d\n",bs1.a,bs1.b,bs1.c);

    pbs1 = &bs1;
    pbs1->a = 0;
    pbs1->b &= 1;
    pbs1->c |= 3;

    printf("%d,%d,%d\n",pbs1->a,pbs1->b,pbs1->c);
}



int main_bak(int argc, char *argv[])
{
    printf("Hello World!\n");
    assert(1 == 1);

    //    char *my_argv[] = {argv[0], "9090"};
    //    test_epoll(2, my_argv);
    //    hello();
    //    test_func_pointer();
    //    test_longjmp();
    //    test_goto(0);
    //    test_goto(1);
    //    test_goto(2);
    test_bit_field();

    printf("%d\n", ADD(1, 2));


    return EXIT_SUCCESS;
}

