#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/select.h>
#include<poll.h>
#include<sys/time.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
    fd_set     rfds, wfds;
    int     fd, result;
    char     buf[10];
    struct pollfd fds[2];
    if((fd =open("tempselect", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) < 0)
        printf("opentempselect error");
    FD_ZERO(&rfds);
    FD_ZERO(&wfds);
    FD_SET(fd, &rfds);
    FD_SET(STDIN_FILENO,&wfds);
    if((result =select(fd+1, &rfds, &wfds, NULL, NULL)) == -1)
        perror("selecterror");
    else if(result == 0)
        printf("no fdready\n");
    else
    {
        printf("%d fd(s) ready\n",result);
        if(FD_ISSET(fd,&rfds))
            printf("fd isready for read\n");
        if(read(fd, buf, 10)< 0)
            perror("readfd error");
        if(FD_ISSET(STDIN_FILENO, &wfds))
            printf("STDINis ready for write\n");
    }
    fds[0].fd = fd;
    fds[0].events = POLLIN;
    fds[1].fd = STDIN_FILENO;
    fds[1].events = POLLOUT;
    if((result = poll(fds, 2,-1)) == -1)
        perror("pollerror");
    else
    {
        printf("%d fd(s)ready\n", result);
        if(fds[0].revents ==POLLIN)
            printf("fd isready for read\n");
        if(read(fd, buf, 10)< 0)
            perror("readfd error");
        if(fds[1].revents ==POLLOUT)
            printf("STDINis ready for write\n");
    }
    exit(0);
}
