#include "longjmp_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <setjmp.h>



static
void test(jmp_buf *env)
{
    printf("1....\n");
    longjmp(*env, 10);
}

void test_longjmp()
{
    jmp_buf env;
    printf("test_longjmp s1\n");
    int ret = setjmp(env);     // 执⾏ longjmp 将返回该位置，ret 等于 longjmp 所提供的状态码。
    printf("test_longjmp ret=%d\n", ret);
    if (ret == 0)
    {
        test(&env);
    }
    else
    {
        printf("2....(%d)\n", ret);
    }
}

void test_goto(int i)
{
    printf("test_goto start\n");
    if (i == 1) {
        goto err1;
    } else if (i == 2) {
        goto err2;
    } else {
        printf("error");
    }
    printf("test_goto end\n");
//    return;

    err1:printf("err1\n");
    err2:printf("err2\n");
}
