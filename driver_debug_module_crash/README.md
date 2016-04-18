#Driver debug module crash sample code
This sampe demo how to debug module crash.

# How to setup build code environment
1. install build code tools
<pre>
sudo apt-get install build-essential
</pre>
2. check wehether kernel header files exist.
<pre>
ls /lib/modules/$(uname -r)/build
</pre>
you will see result like below:
![result link](http://139.162.35.49/image/Linux-Programming/small_template_20160414.png)

3. if kernel header files doesn't exist, try to install them.
<pre>
sudo apt-get install linux-headers-$(uname -r)
</pre>

#Code Description
1. write `char* ptr=NULL, *ptr=0` in the driver, this cause driver crash: [drv_caller.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_debug_module_crash/drv_src/drv_caller/drv_caller.c)
<pre>
void test_fn(){
        printk("<1>drv_caller: open\n");
        char* ptr=NULL;
        *ptr=0;
}
</pre>

2. create `drv_caller.ko` assembly+c code file `drv_caller.s` for debug: [mk.sh](https://github.com/ivan0124/Linux-programming/blob/master/driver_debug_module_crash/mk.sh)
<pre>
...
objdump -S drv_caller.ko > drv_caller.s
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>
2. check `build` directory and find out build result 
<pre>
app_a - application which set ioctl command to drv_caller.ko
drv_caller.ko - driver which cause crash
drv_caller.sh - script for install and uninstall driver
</pre>
3. install driver drv_caller.ko
<pre>
$ mk.sh install
</pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: init
</pre>

4. run app_a to test
<pre>$ mk.sh test </pre>

5. check the syslog by typing `dmesg`, code crash at address `e0a6d0a7`:
![result link](http://139.162.35.49/image/Linux-Programming/driver_debug_module_crash_20160418_1.png)

6. type `dmesg | tail` and found the maximum module address is `1d7`, so the base addres is `e0a6d000`:
![result link](http://139.162.35.49/image/Linux-Programming/driver_debug_module_crash_20160418_0.png)

7. check the `drv_caller.s` and find out the crash code is `*ptr=0` in `test_fn`:
![result link](http://139.162.35.49/image/Linux-Programming/driver_debug_module_crash_20160418_2.png)

8. uninstall drivers
<pre>
$ mk.sh uninstall
</pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: exit
</pre>

9. remove all build result
<pre>
$ mk.sh clean
</pre>


