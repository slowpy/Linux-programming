#Small Template Sample code
This is a sample to demo how to bulid app, library and driver by Makefile.

#How to test
1. build code
<pre>$ make</pre>
2. set LD_LIBRARY_PATH environment variable to export shared library path
<pre>$ export LD_LIBRARY_PATH=$(pwd)/build</pre>
3. check build folder and find out build result 
<pre>
app_a - application
lib_demo_a.so, lib_demo_b.so - shared library
hello.ko - driver
</pre>
4. run app_a and see some log from shared library.
<pre>$ ./app_a </pre>
you will see logs:
<pre>
test_lib_a() is called (in lib_a.c)
test_lib_a1() is called (in lib_a1.c)
</pre>

5. install and uninstall driver: check the README.md of 
[drv_a](https://github.com/ivan0124/Linux-programming/tree/master/small_template/drv_src/drv_a)

6. remove all build result
<pre>$ make clean</pre> 


