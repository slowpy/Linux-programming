#Driver Export function Sample code
This sampe demo the driver how to export function and the driver how to use the exported function.

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
1. the driver `drv_callee.ko` export function `export_hello()`: [drv_callee.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_export_function/drv_src/drv_callee/drv_callee.c)
<pre>
...
int export_hello(void) {
    printk("Hello from another module");
    return 0;
} 
...
EXPORT_SYMBOL(export_hello);
</pre>

2. copy `drv_callee` Modules.symvers to the `drv_caller`: [Makefile](https://github.com/ivan0124/Linux-programming/blob/master/driver_export_function/drv_src/drv_callee/Makefile)
<pre>
...
@cp -rf Module.symvers ../drv_caller/
...
</pre>

3. declare function `export_hello()` and calling it: [drv_caller.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_export_function/drv_src/drv_caller/drv_caller.c)
<pre>
...
extern int export_hello(void);
...
export_hello();
...
</pre>

4. `app_a` set ioctl to `drv_callee.ko` to trigger the test: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_export_function/app_src/app_a/app_a.c)
<pre>
...
ioctl(file_desc, IOCTL_SET_MSG, message);
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>
2. check `build` directory and find out build result 
<pre>
app_a - application which set ioctl to drv_caller.ko 
drv_callee.sh, drv_caller.sh - script for install and uninstall driver
drv_callee.ko - driver which export function 'export_hello()' 
drv_caller.ko - driver which calling exported function 'export_hello()'
</pre>
3. install driver drv_callee.ko and drv_caller.ko
<pre>
$ mk.sh install
</pre>
type `dmesg`, you will see below logs
<pre>
drv_callee: init
drv_caller: init
</pre>

4. run app_a to test
<pre>$ mk.sh test </pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: ioctl
drv_caller: enter IOCTL_SET_MSG
drv_callee: export_hello() is called
drv_caller: close
</pre>

5. uninstall drivers
<pre>
$ mk.sh uninstall
</pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: exit
drv_callee: exit
</pre>


6. remove all build result
<pre>
$ mk.sh clean
</pre>


