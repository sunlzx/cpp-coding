#include <stdio.h>
#include "mylib.h"

int main(int argc,  char *argv[])
{
    printf("argc:%d\n", argc);
    int i = 0;
    for(i=0; i<argc; i++)
    {
        printf("argv[%d]:%s\n", i, argv[i]);
    }

    int a = 1;
    int b = 2;
    printf("%d + %d = %d\n", a, b, myadd(a, b));
}
