#Small Template Sample code
This is a sample to demo how to bulid app, library and driver by Makefile.

# How to setup build code environment
1. install build code tools
<pre>
$ sudo apt-get install build-essential
</pre>
2. check wehether kernel header files exist.
<pre>
$ ls /lib/modules/$(uname -r)/build
</pre>
you will see result like below:
![result link](http://139.162.35.49/image/Linux-Programming/small_template_20160414.png)

3. if kernel header files doesn't exist, try to install them.
<pre>
$ sudo apt-get install linux-headers-$(uname -r)
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


