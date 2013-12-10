#ifndef UTILITY_H
#define UTILITY_H

#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

namespace mystd {

int add(int a, int b)
{
    return a + b;
}

/**
 * @brief exec_cmd
 * @param cmd
 * @param result
 * @return
 */
int exec_cmd(const char *cmd, char *result)
{
    int status = -1;
    char buf_ps[1024];
    char ps[1024]={0};
    FILE *ptr;
    strcpy(ps, cmd);
    if((ptr=popen(ps, "r"))!=NULL)
    {
        while(fgets(buf_ps, 1024, ptr)!=NULL)
        {
           strcat(result, buf_ps);
           if(strlen(result)>1024)
               break;
        }
        status = pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", ps);
    }
    return status;
}

}

#endif // UTILITY_H
