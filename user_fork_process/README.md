#For process Sample code
This sample demo how to fork process.

![fork flow link](http://139.162.35.49/image/Linux-Programming/user_fork_process_20160415_1.png)

#Code Description
1. calling `fork()` to copy process
<pre>
int main(void){
...
    pid = fork();
...
</pre>

2. `fork()` return pid 0 is child process (Process B): [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_fork_process/app_src/app_a/app_a.c)
<pre>
int main(void){
...
        if(pid == 0){
            log("[child process] pid = %d,parent's pid = %d\n",getpid(),getppid());
	        exit(99);
    }
...
</pre>
3. `fork()` return pid > 0 is parent process(Process A): [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_fork_process/app_src/app_a/app_a.c)
<pre>
int main(void){
...
        if(pid > 0){
            log("[parent process] pid =%d ,child's pid = %d\n",getpid(),pid);
...
</pre>

4. using `wait()` clear child `zombie` process
<pre>
int main(void){
...
        child_pid = wait(&stat_val);
...
</pre>



#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
lib_demo_a.so, lib_demo_b.so, lib_common.so - shared library
drv_hello.ko - driver
</pre>

3. install driver.
<pre>$ mk.sh install</pre>
type `dmesg` to see below logs
<pre>
drv_hello: init
</pre>

4. run app_a to test. you will see some logs in the screen.
<pre>$ mk.sh test </pre>


5. uninstall driver
<pre>$ mk.sh uninstall</pre>
type `dmesg` to see below logs
<pre>
drv_hello: exit
</pre>

6. remove all build result
<pre>$ mk.sh clean</pre> 


