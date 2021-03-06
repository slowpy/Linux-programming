/* udp_client.c */

#include <stdio.h>
#include <netinet/in.h>
#include "lib_common.h"

int main(int argc, char*argv[])
{
  int sock, status, buflen, sinlen;
  char buffer[256]={0};
  struct sockaddr_in sock_in;
  int yes = 1;

  sinlen = sizeof(struct sockaddr_in);
  memset(&sock_in, 0, sinlen);

  sock = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);

  sock_in.sin_addr.s_addr = htonl(INADDR_ANY);
  sock_in.sin_port = htons(60000);
  sock_in.sin_family = PF_INET;

  status = bind(sock, (struct sockaddr *)&sock_in, sinlen);
  log("\nBind Status = %d\n", status);

  status = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int) );
  //log("Setsockopt Status = %d\n", status);

  sprintf(buffer, "hello, udp test");
  buflen = strlen(buffer);

  log("sendto  data=%s\n", buffer);
  status = sendto(sock, buffer, buflen, 0, (struct sockaddr *)&sock_in, sinlen);

  shutdown(sock, 2);
  close(sock);

}

