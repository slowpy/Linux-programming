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

4. [server side] using `recvfrom()` to wait and receive data come in ( if no data, we will block here until timeout ):
<pre>
...
    status = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&sock_in, &sinlen);
...
</pre>

5. [server side] using `shutdown()` to stop sokcet operation and `close` to close socket:
<pre>
...
  shutdown(sock, 2);
  close(sock);
...
</pre>

6. [client side] using `socket()` to create UDP socket: [udp_client](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/client/udp_client.c)
<pre>
...
    sock = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);
...
</pre>

7. [client side] using `bind()` to bind socket with `IP address`, `port` and `network family`: [udp_client](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/client/udp_client.c)
<pre>
...
    sock_in.sin_addr.s_addr = htonl(INADDR_ANY);
    sock_in.sin_port = htons(60000);
    sock_in.sin_family = PF_INET;

    status = bind(sock, (struct sockaddr *)&sock_in, sinlen);
...
</pre>

8. [client side] using `setsockopt()` set socket to broadcast UDP packets: [udp_client](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/client/udp_client.c)
<pre>
...
    status = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int) );
...
</pre>

9. [client side] using `sendto()` to broadcast UDP packets: [udp_client](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/client/udp_client.c)
<pre>
...
    status = sendto(sock, buffer, buflen, 0, (struct sockaddr *)&sock_in, sinlen);
...
</pre>

10. [client side] using `shutdown()` to stop sokcet operation and `close` to close socket: [udp_client](https://github.com/ivan0124/Linux-programming/blob/master/user_udp_broadcast_client_server/app_src/client/udp_client.c)
<pre>
...
  shutdown(sock, 2);
  close(sock);
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


