#select function Sample code
This sample demo how to use select function.

#Code Description
1. declare `fd`, `fdset` and `nfds`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_select/app_src/app_a/app_a.c)
<pre>
...
    int fd=0;
    fd_set fdset;
    int nfds=0;
...
</pre>

2. get file description `fd`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_select/app_src/app_a/app_a.c)
<pre>
    while(1){
...
        fd = open(myfifo, O_RDONLY | O_NONBLOCK);
...
</pre>

3. set maximum fd `nfds` for `select()`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_select/app_src/app_a/app_a.c)
<pre>
...
        nfds=fd+1;
...
        if ((ready_fd = select(nfds,&fdset,NULL,NULL,NULL))<0){
...
</pre>

4. initialize `fdset` as zero and add `fd` to `fdset`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_select/app_src/app_a/app_a.c)
<pre>
...
        FD_ZERO(&fdset);
        FD_SET(fd,&fdset);
...
</pre>

5. using `select()` to wait `fd` message come in(we will block here): [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_select/app_src/app_a/app_a.c)
<pre>
...
        if ((ready_fd = select(nfds,&fdset,NULL,NULL,NULL))<0){
...
</pre>

6. check if `fd` has message come in, if yes, read `fd` message: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_select/app_src/app_a/app_a.c)
<pre>
...
        if (FD_ISSET(fd,&fdset)){
    	    read(fd, buf, MAX_BUF);
...
</pre>

7. close `fd` and clear `fdset`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_select/app_src/app_a/app_a.c)
<pre>
...
        close(fd);
        FD_CLR(fd,&fdset);
...
</pre>



#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - create pipe and wait to read pipe message
app_b - write 'Hi' message to app_a
</pre>

3. run app_a to test. you will see some logs in the screen.
<pre>$ mk.sh test </pre>


4. remove all build result
<pre>$ mk.sh clean</pre> 


