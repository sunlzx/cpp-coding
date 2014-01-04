#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#define MAXLINE 1024

int main_test(int argc, char *argv[])
{
    printf("http server start..\n");
    int servport = 8888;
    char buf[MAXLINE];

    int i=0;
    for (i=1; i<argc; i++) {
        if(strcmp("-p", argv[i])) {
            servport = atoi(argv[i+1]);
        }
    }

    printf("listen port:%d\n", servport);

    struct sockaddr_in servaddr, cliaddr;
    int listenfd;
    int connfd;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(servport);

    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    int ret = listen(listenfd, 50);
    printf("linsten ret:%d\n", ret);

    printf("start accept ....\n");
    while(1) {

        socklen_t cliaddr_len = sizeof(cliaddr);

        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);
        char str[INET_ADDRSTRLEN];
        printf("recieve client: %s:%d \n",
               inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
               ntohs(cliaddr.sin_port));

        read(connfd, buf, MAXLINE);
        printf("request:\n");
        printf(buf);
        memset(&buf, 0, MAXLINE);

        char *res = "HTTP/1.1 200 OK\r\n";

        write(connfd, res, strlen(res));

        close(connfd);
        printf("close connection\n");
    }






    return EXIT_SUCCESS;
}

