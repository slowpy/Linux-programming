#UDP broadcast client/server Sample code
This sample demo how to broadcast and receive udp packets.

# Code Description
1. [server side] using `socket()` to create UDP socket: [udp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/server/udp_server.c)
<pre>
...
sock = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);
...
</pre>

2. [server side] using `setsockopt()` to set socket timeout which avoid `recvfrom()` block too long: [udp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/server/udp_server.c)
<pre>
...
  struct timeval tv;
  tv.tv_sec = 65536;
  tv.tv_usec = 0;
  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(tv)) < 0) {
...
</pre>

3. [server side] using `bind()` to bind socket with `IP address`, `port` and `network family`: [udp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/server/udp_server.c)
<pre>
...
  sock_in.sin_addr.s_addr = htonl(INADDR_ANY); //receive all network interface data
  sock_in.sin_port = htons(60000); //receive port 60000 data
  sock_in.sin_family = PF_INET; //internet family

  status = bind(sock, (struct sockaddr *)&sock_in, sinlen);
...
</pre>

4. [server side] using `recvfrom()` to wait and receive data come in ( it no data, we will block here until timeout ):
<pre>
...
status = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&sock_in, &sinlen);
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
udp_client - application which broadcast udp packets
udp_server - application which receive udp packets
lib_common.so - shared library
</pre>

3. type `mk.sh test` to test. you will see test result like below:
<pre>$ mk.sh test </pre>

4. remove all build result
<pre>$ mk.sh clean</pre> 


