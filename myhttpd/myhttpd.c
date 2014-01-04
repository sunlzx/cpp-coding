
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
#include <string.h>

#define MAXLINE 1024
#define MAXEVENTS 100
#define MAXEPOLLSIZE 100

int main_m(int argc, char *argv[])
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
    socklen_t cliaddr_len;
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


    struct epoll_event event;
    struct epoll_event *events;
    int epfd;
    int s;

    epfd = epoll_create1(0);
    event.data.fd = listenfd;
    event.events = EPOLLIN | EPOLLET;

    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &event);
    if (s == -1) {
        perror ("epoll_ctl");
        abort ();
    }

    /* Buffer where events are returned */
    events = (struct epoll_event *)calloc(MAXEVENTS, sizeof event);

    int curfds = 0;
    int acceptCount = 0;

    while(1) {

        int n, i;

        n = epoll_wait(epfd, events, MAXEVENTS, 0);
        for(i=0; i<n; i++) {
            if(listenfd == events[i].data.fd) {
                connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
                sprintf(buf, "accept form %s:%d\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);
                printf("%d:%s", ++acceptCount, buf);

                if (curfds >= MAXEPOLLSIZE) {
                    fprintf(stderr, "too many connection, more than %d\n", MAXEPOLLSIZE);
                    close(connfd);
                    continue;
                }
                if (setnonblocking(connfd) < 0) {
                    perror("setnonblocking error");
                }
                event.events = EPOLLIN | EPOLLET;
                event.data.fd = connfd;
                if (epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &event) < 0)
                {
                    fprintf(stderr, "add socket '%d' to epoll failed: %s\n", connfd, strerror(errno));
                    return -1;
                }
                curfds++;
                continue;
            }
        }

    }

//    socklen_t cliaddr_len = sizeof(cliaddr);

//    connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);
//    char str[INET_ADDRSTRLEN];
//    printf("recieve client: %s:%d \n",
//           inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
//           ntohs(cliaddr.sin_port));

//    read(connfd, buf, MAXLINE);
//    printf("request:\n");
//    printf(buf);
//    memset(&buf, 0, MAXLINE);

//    char *res = "HTTP/1.1 200 OK\r\n";

//    write(connfd, res, strlen(res));

//    close(connfd);
//    printf("close connection\n");



    return EXIT_SUCCESS;
}

