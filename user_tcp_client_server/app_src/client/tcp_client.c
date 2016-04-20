/* tcp_client.c */

#include <stdio.h>
#include <netinet/in.h>
#include "lib_common.h"

int main(int argc, char*argv[])
{
   int sockfd;
   struct sockaddr_in dest;
   char buffer[128];
   char resp[16]="client ack";

   /* create socket */
   sockfd=socket(PF_INET, SOCK_STREAM, 0);

   /* initialize value in dest */
   bzero(&dest, sizeof(dest));
   dest.sin_family = PF_INET;
   dest.sin_port = htons(8889);
   dest.sin_addr.s_addr = inet_addr("127.0.0.1");
   //inet_aton("127.0.0.1", &dest.sin_addr);

   /* Connecting to server */
   log("connecting to server...\n");
   connect(sockfd, (struct sockaddr*)&dest, sizeof(dest));

   /* Receive message from the server and print to screen */
   bzero(buffer, sizeof(buffer));
   recv(sockfd, buffer, sizeof(buffer), 0);
   log("receive from server: %s\n", buffer);
   send(sockfd, resp, strlen(resp),0);

   /* close connection */
   close(sockfd);
   log("client close connection.\n");
}

