/* tcp_server.c */
#include <stdio.h>
#include <netinet/in.h>
#include "lib_common.h"

int main()
{
    int sockfd;
    struct sockaddr_in dest; 
    char buffer[32]="Hi client";
    char buffer1[32];
    
    /*create socket*/
    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    /* initialize structure dest*/
    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8889);
    dest.sin_addr.s_addr = INADDR_ANY;
    
    /* Assign a port number to socket*/
    bind(sockfd, (struct sockaddr*)&dest, sizeof(dest));

    /*make it listen to socket with max 20 connection*/
    listen(sockfd, 20);

    /*infinity loop -- accepting connection from client forever*/
    while(1){
        int clientfd;
        struct sockaddr_in client_addr;
        int addrlen = sizeof(client_addr);

        /*Wait and Accept connection*/
        log("wait client connection...\n");
        clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);

        /*Send message*/
        log("send to client:%s\n", buffer);
        send(clientfd, buffer, sizeof(buffer), 0);

        int res=recv(clientfd, buffer1, sizeof(buffer1),0);
        log("receive from client: %s, %d bytes\n", buffer1, res);
        //write(fd,buffer1,sizeof(buffer1));

        close(clientfd);
        break;
    }

    /*close server*/
    close(sockfd);
    log("close server\n");
    return 0;
}

