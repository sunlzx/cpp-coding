#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>

#include "tpool.h"



int exec_cmd(const char *cmd, char **result_pp)
{
    assert(cmd);
    assert(result_pp);

    int status = -1;
    char buf_ps[1024];
    //    char ps[1024]={0};
    //    strcpy(ps, cmd);
    FILE *ptr;

    int init_size = 1024;
    int len = init_size;

//    char *result = (char*)malloc(init_size);
//    bzero(result, init_size);

    char *result = (char*)calloc(sizeof(char),init_size);


    *result_pp = result;


    if((ptr=popen(cmd, "r"))!=NULL)
    {
        while(fgets(buf_ps, 1024, ptr)!=NULL)
        {
            int str_len = strlen(buf_ps) + strlen(result);
            if(str_len >= len - 1)
            {
                result = (char*)realloc(result, len * 2);
                *result_pp = result;
                len = len * 2;
            }

            strcat(result, buf_ps);
            bzero(buf_ps, 1024);
        }
        status = pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", cmd);
    }
    return status;
}



void pool_execute(const char *cmd)
{
    char *result;
    int status = exec_cmd(cmd, &result);
    printf("cmd: %s, len: %d \n", cmd, strlen(result));
//    printf("cmd result, status: %d \nresult: \n%s", status, result);
    free(result);
    result = NULL;
}

/**
 * @brief main
 * @param argc
 * @param argv
 *      argv[0]:cmd
 *      argv[1]:exec times
 * @return
 */
int main(int argc, char *argv[])
{
    printf("Usage:./monitor cmd -n 100 -c 1\n");
    printf("argc: %d \n", argc);
    if (argc < 6) {
        return EXIT_FAILURE;
    }

    char *cmd = argv[1];
    int exec_times = 1;
    int max_concurrent = 1;

    int i=0;
    for(i=2; i<argc; i+=2) {
        if (strcmp("-c", argv[i])) {
            exec_times = atoi(argv[i + 1]);
        }
        if (strcmp("-n", argv[i])) {
            max_concurrent = atoi(argv[i + 1]);
        }
    }
    printf("exec_times %d, concurrent:%d\n", exec_times, max_concurrent);


    tpool_t thread_pool;
    if (max_concurrent > 1) {
        tpool_init(&thread_pool, max_concurrent, max_concurrent * 2);
    }

    struct timeval tpstart,tpend;
    float timeuse;
    /* start time */
    gettimeofday(&tpstart,NULL);

    for(i=0; i<exec_times; i++) {
        if (max_concurrent <= 1) {
            pool_execute(cmd);
        }
        else {
            tpool_add_work(thread_pool, pool_execute, (void *)cmd);
        }
    }
    if (max_concurrent > 1) {
        tpool_destroy(thread_pool, 1);
    }
    gettimeofday(&tpend,NULL);
    timeuse=1000000*(tpend.tv_sec-tpstart.tv_sec)+
            tpend.tv_usec-tpstart.tv_usec;

    printf("Used Time:%f\n",timeuse / 1000);
    return EXIT_SUCCESS;
}


