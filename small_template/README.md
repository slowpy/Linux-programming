#Small Template Sample code
This is a sample to demo how to bulid app, library and driver by Makefile.

#How to test
1. build code
<pre>$ make</pre>
2. check build folder and find out build result 
<pre>
app_a - application
lib_demo_a.so, lib_demo_b.so - shared library
hello.ko - driver
</pre>
3. run app_a and see some log from shared library.
<pre>$ ./app_a </pre>

4. install and uninstall driver: check the README.md of 
[drv_a](https://github.com/ivan0124/Linux-programming/tree/master/small_template/drv_src/drv_a)

4. remove all build result
<pre>$ make clean</pre> 


