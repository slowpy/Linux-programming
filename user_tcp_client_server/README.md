#TCP client/server Sample code
This sample demo how to send and receive TCP packets.
![result link](http://139.162.35.49/image/Linux-Programming/user_tcp_client_server_20160420.gif)

# Code Description
1. [server side] using `socket()` to create TCP `socket fd`(sockfd): [tcp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/server/tcp_server.c)
<pre>
...
sockfd = socket(PF_INET, SOCK_STREAM, 0);
...
</pre>
when `tcp_server` is running. type `ls /proc/{PID}/fd -al`, you can find `socket fd` (sock). example as below (PID=2227):
![result link](http://139.162.35.49/image/Linux-Programming/find_socket_process_20160419_4.png)


2. [server side] using `bind()` to bind socket with `IP address`, `port` and `network family`: [tcp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/server/tcp_server.c)
<pre>
...
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8889);
    dest.sin_addr.s_addr = INADDR_ANY;
...
    bind(sockfd, (struct sockaddr*)&dest, sizeof(dest));
...
</pre>

3. [server side] make it listen to socket with max 20 connection : [tcp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/server/tcp_server.c)
<pre>
...
    listen(sockfd, 20);
...
</pre>

4. [server side] using `accept()` to wait client connection.(we will block here): [tcp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/server/tcp_server.c)
<pre>
...
    clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);
...
</pre>

5. [server side] when connection established we get socket fd `clientfd`, then send data to client by this `clientfd`: [tcp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/server/tcp_server.c)
<pre>
...
    clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);
    send(clientfd, buffer, sizeof(buffer), 0);
...
</pre>

6. [server side] using `recv()` to receive data from client: [tcp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/server/tcp_server.c)
<pre>
...
    int res=recv(clientfd, buffer1, sizeof(buffer1),0);
...
</pre>

7. [server side] close socket when it is not used: [tcp_server.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/server/tcp_server.c)
<pre>
...
    close(clientfd);
...
    close(sockfd);
...
</pre>

8. [client side] using `socket()` to create TCP `socket fd`(sockfd): [tcp_client.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/client/tcp_client.c)
<pre>
...
sockfd=socket(PF_INET, SOCK_STREAM, 0);
...
</pre>

9. [client side] using `connect()` to connect server `127.0.0.1:8889`: [tcp_client.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/client/tcp_client.c)
<pre>
...
   dest.sin_family = PF_INET;
   dest.sin_port = htons(8889);
   dest.sin_addr.s_addr = inet_addr("127.0.0.1");
...
   connect(sockfd, (struct sockaddr*)&dest, sizeof(dest));
...
</pre>

10. [client side] using `recv()` to receive server data: [tcp_client.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/client/tcp_client.c)
<pre>
...
    recv(sockfd, buffer, sizeof(buffer), 0);
...
</pre>

11. [client side] using `send()` to send data to server: [tcp_client.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/client/tcp_client.c)
<pre>
...
    send(sockfd, resp, strlen(resp),0);
...
</pre>

12. [client side] close socket when is is not used: [tcp_client.c](https://github.com/ivan0124/Linux-programming/blob/master/user_tcp_client_server/app_src/client/tcp_client.c)
<pre>
...
  close(sockfd);
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

3. type `mk.sh test` to test. 
<pre>$ mk.sh test </pre>
you can see test result like below:
![result link](http://139.162.35.49/image/Linux-Programming/find_socket_process_20160419_5.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


