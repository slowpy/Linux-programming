#Non-block pipe Sample code
This sample demo how to create pipe and read/write it.

#Code Description
1. create pipe by using `mkfifo`, the pipe name is `/tmp/myfifo`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_non_block_pipe/app_src/app_a/app_a.c)
<pre>
int main()
{
...
        char * myfifo = "/tmp/myfifo";
...
        while(1){
...
            if ( mkfifo(myfifo, 0666) < 0 ){
...
</pre>

2. open `/tmp/myfifo` to read and on non-block mode by using parameters `O_RDONLY | O_NONBLOCK`, so we don't block on `open()`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_non_block_pipe/app_src/app_a/app_a.c)
<pre>
int main()
{
...
        while(1){
...
            fd = open(myfifo, O_RDONLY | O_NONBLOCK);
...
</pre>

3. using `select` to wait pipe message come in, we will block here until message come in: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_non_block_pipe/app_src/app_a/app_a.c)
<pre>
int main()
{
...
        while(1){
...
        if ((ready_fd = select(nfds,&fdset,NULL,NULL,NULL))<0){
...
</pre>

4. oepn and write 'Hi' message to `/tmp/myfifo`:
<pre>
int main()
{
        int fd;
        char * myfifo = "/tmp/myfifo";

        fd = open(myfifo, O_WRONLY);
        write(fd, "Hi", sizeof("Hi"));
        close(fd);
...
</pre>

5. read `/tmp/myfifo` pipe message: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_non_block_pipe/app_src/app_a/app_a.c)
<pre>
int main()
{
...
        while(1){
...
        read(fd, buf, MAX_BUF);
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
you will see logs like below:
![result link](http://139.162.35.49/image/Linux-Programming/user_non_block_pipe_20160415.png)


4. remove all build result
<pre>$ mk.sh clean</pre> 


