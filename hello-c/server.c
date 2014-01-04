#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 80
#define SERV_PORT 8888

int main_server(int argc, int *argv[]) {
    printf("server start...\n");

    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(listenfd, 20);

    printf("Accepting connections...\n");

    while(1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
        printf("accetp connection...\n");
        n = read(connfd, buf, MAXLINE);
        printf("received from %s at port %d \n",
               inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
               ntohs(cliaddr.sin_port));
        for(i=0; i<n; i++) {
            buf[i] = toupper(buf[i]);
        }
        write(connfd, buf, sizeof(buf));
        close(connfd);
        printf("close connection...\n");
        bzero(&buf, sizeof(buf));
    }
    return EXIT_SUCCESS;
}
