#fork process Sample code
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

4. Process A using `wait()` to clear child `zombie` process: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_fork_process/app_src/app_a/app_a.c)
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
</pre>

3. run app_a to test.
<pre>$ mk.sh test </pre>
you will see the logs like below
![result link](http://139.162.35.49/image/Linux-Programming/user_fork_process_20160415.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


