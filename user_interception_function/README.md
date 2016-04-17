#interception function Sample code
This sample demo how to replace exist function to yours.

#Code Description
1. we will intercept `malloc()`. redefine `malloc()` as ours: [interception.h](https://github.com/ivan0124/Linux-programming/blob/master/user_interception_function/app_src/app_a/interception.h)
<pre>
...
#define malloc(n) my_malloc(n)
void* my_malloc(int size);
...
</pre>

2. implement `my_malloc()`: [interception.c](https://github.com/ivan0124/Linux-programming/blob/master/user_interception_function/app_src/app_a/interception.c)
<pre>
void* my_malloc(int size){
        printf("malloc interception <=========\n");
}
</pre>

3. calling `malloc()`, you will see it actually call `my_malloc()` : [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_interception_function/app_src/app_a/app_a.c)
<pre>
int main( int argc, char* argv[])
{
        malloc(100);
        return 0;
}
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


