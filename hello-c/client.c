#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>


#define MAXLINE 80
#define SERV_PORT 8888

int main_client(int argc, int *argv[]) {
    printf("client start ...\n");

    if (argc < 2) {
        fputs("Usage:./a.out message \n", stderr);
        exit(1);
    }

    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char *str;

    str = argv[1];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    write(sockfd, str, strlen(str));
    n = read(sockfd, buf, MAXLINE);
    printf("Response from server: \n");
    write(STDOUT_FILENO, buf, n);


    close(sockfd);




    return EXIT_SUCCESS;
}
