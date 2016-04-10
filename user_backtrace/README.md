#Backtrace Sample code
This sample demo how to generate and analyze backtrace.

#Code Description
1. register function for segmentation fault signal : int the code ./user_backtrace/app_src/app_a/app_a.c
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

2. print application memory mapping: int the code ㄡ/user_backtrace/app_src/app_a/app_a.c
<pre>
void dump(int signo)
{
...
    snprintf(cmd,sizeof(cmd),"cat /proc/%d/maps",getpid());
    system(cmd);
...
</pre>

3. calling function to print call stack: in the code ./user_backtrace/app_src/app_a/app_a.c
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

4. let objdump can generate C source code: in the code ./user_backtrace/app_src/app_a/Makefile
<pre>
...
CFLAGS :=-g
...
</pre>

5. generate `app_a.s` file: in the code /user_backtrace/mk.sh
<pre>
...
objdump -S ./app_a > app_a.s
...
</pre>


#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
app_a.s - disassemble and source code for app_a
</pre>

3. run app_a to test. you will see some logs in the screen.
<pre>$ mk.sh test </pre>
you will see test result as below:
![test result link](http://139.162.35.49/image/Linux-Programming/user_backtrace_20160410_1.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 

#How to mapping backtrace address's source code
1. find out address `0x400927` belong which binary
![select backtrace log](http://139.162.35.49/image/Linux-Programming/user_backtrace_20160410_1.png)
2. from step1, we know it belong `app_a`. so check the `app_a.s` and find out address `0x400927` belong `func_c` function. 
![select backtrace log](http://139.162.35.49/image/Linux-Programming/user_backtrace_20160410_2.png)
