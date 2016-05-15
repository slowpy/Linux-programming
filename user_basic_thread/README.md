#Basic thread Sample code
This sample demo how to create thread.

#Code Description
1. create thread: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_basic_thread/app_src/app_a/app_a.c)
<pre>
...
ret=pthread_create(&id,NULL,(void *) thread,NULL);
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
</pre>

3. run app_a to test. you will see some logs in the screen.
<pre>$ mk.sh test </pre>


4. remove all build result
<pre>$ mk.sh clean</pre> 


