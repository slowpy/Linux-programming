#Shared library backtrace Sample code
This sample demo how to generate and analyze backtrace.

#Code Description
1. register function for segmentation fault signal : [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_shared_library_backtrace/app_src/app_a/app_a.c)
<pre>
...
void dump(int signo)
{
...
}
...
int main(){
        signal(SIGSEGV, dump);
...
}
</pre>

2. print application memory mapping: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_shared_library_backtrace/app_src/app_a/app_a.c)
<pre>
void dump(int signo)
{
...
    snprintf(cmd,sizeof(cmd),"cat /proc/%d/maps",getpid());
    system(cmd);
...
</pre>

3. calling function to print call stack: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_shared_library_backtrace/app_src/app_a/app_a.c)
<pre>
void dump(int signo)
{
...
        size = backtrace (array, 30);
        strings = backtrace_symbols (array, size);
 
        fprintf (stderr,"Obtained %zd stack frames.nm\n", size);
 
        for (i = 0; i < size; i++)
            fprintf (stderr,"%sn\n", strings[i]);
...
}
</pre>

4. let objdump can generate C source code: lib_demo_a [Makefile](https://github.com/ivan0124/Linux-programming/blob/master/user_shared_library_backtrace/lib_src/lib_demo_a/Makefile)
<pre>
...
CFLAGS +=-g
...
</pre>

5. generate `lib_demo_a.s` file: [mk.sh](https://github.com/ivan0124/Linux-programming/blob/master/user_shared_library_backtrace/mk.sh)
<pre>
...
objdump -S ./lib_demo_a.so > lib_demo_a.s
...
</pre>


#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
lib_demo_a.so - shared library
lib_demo_a.s - disassemble and source code for lib_demo_a.so
</pre>

3. run app_a to test. you will see some logs in the screen.
<pre>$ mk.sh test </pre>
you will see test result as below:
![test result link](http://139.162.35.49/image/Linux-Programming/user_shared_library_backtrace_20160410_1.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 

#How to mapping backtrace address's source code
1. find out address `0x7f7263656788` belong which binary
![select backtrace log](http://139.162.35.49/image/Linux-Programming/user_shared_library_backtrace_20160410_1.png)
2. caculate the address in the shared library:
<pre>
0x7f7263656000 - from /proc/{PID}/maps, you can find in the above step 1.
0x7f7263656788 - backtrace address, you can find in the above step 1
0x7f7263656788 - 0x7f7263656000 = 0x788
</pre>

3. from step1 & step2 we know it belong `lib_demo_a.so`. so check the `lib_demo_a.s` and find out address `0x788` belong `test_lib_a()` function.
![select backtrace log](http://139.162.35.49/image/Linux-Programming/user_shared_library_backtrace_20160410_2.png)
