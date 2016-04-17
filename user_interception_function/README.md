#interception function Sample code
This sample demo how to replace exist function to yours.

#Code Description
1. we will intercept `malloc()`. redefine `malloc()` as `my_malloc`: [interception.h](https://github.com/ivan0124/Linux-programming/blob/master/user_interception_function/app_src/app_a/interception.h)
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
</pre>

3. run app_a to test. 
<pre>$ mk.sh test </pre>
you will see logs like below:
![result link](http://139.162.35.49/image/Linux-Programming/user_interception_function_20160417.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


