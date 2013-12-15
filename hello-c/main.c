#include <stdio.h>

#include "epoll_test.h"
#include "func_test.h"



int main_0(int argc, char *argv[])
{
    printf("Hello World!\n");

    char *my_argv[] = {argv[0], "9090"};




//    test_epoll(2, my_argv);
    test_func_pointer();
    hello();

    return 0;
}

