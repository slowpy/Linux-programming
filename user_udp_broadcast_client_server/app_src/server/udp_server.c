/* udp_server.c */
#include <stdio.h>
#include <netinet/in.h>
#include "lib_common.h"

int main()
{
  int sock, status;
  unsigned sinlen;
  unsigned char buffer[256]={0};
  struct sockaddr_in sock_in;
  
  log("\nupd_server ver 0.1\n");

  sinlen = sizeof(struct sockaddr_in);
  memset(&sock_in, 0, sinlen);

  sock = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  
  struct timeval tv;
  tv.tv_sec = 65536;
  tv.tv_usec = 0;
  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(tv)) < 0) {
      log("set timeout error\n");
	  return;
  }
 
  sock_in.sin_addr.s_addr = htonl(INADDR_ANY); //receive all network interface data
  sock_in.sin_port = htons(60000); //receive port 60000 data
  sock_in.sin_family = PF_INET; //internet family

  status = bind(sock, (struct sockaddr *)&sock_in, sinlen);
  log("Bind Status = %d\n", status);

  status = getsockname(sock, (struct sockaddr *)&sock_in, &sinlen);
  log("Sock port: %d\n",htons(sock_in.sin_port));
  
  log("ready to receive data\n");
  while(1){
      memset(buffer, 0, sizeof(buffer));
      status = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&sock_in, &sinlen);
	  
      if (status < 0 ){
          log("\ntimeout reached\n");
	  break;
      }
      else{
	  log("receive data=%s\n",buffer);
      }
	  
  }
	  
  log("stop udp_server\n");
  shutdown(sock, 2);
  close(sock);
}

