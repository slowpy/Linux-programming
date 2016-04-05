#Driver Export function Sample code
This sampe demo the driver how to export function and the driver how to use the exported function.

#Code Description
1. the driver `drv_callee.ko` export function `export_hello()`: in the code ./driver_export_function/drv_src/drv_callee/drv_callee.c
<pre>
...
int export_hello(void) {
    printk("Hello from another module");
    return 0;
} 
...
EXPORT_SYMBOL(export_hello);
</pre>

2. add -DEXPORT_SYMTAB in `drv_callee` and copy `drv_callee` Modules.symvers to the `drv_caller`: in the code ./driver_export_function/drv_src/drv_callee/Makefile
<pre>
...
obj-m := -DEXPORT_SYMTAB
...
@cp -rf Module.symvers ../drv_caller/
...
</pre>

3. declare function `export_hello()` and calling it: in the code ./driver_export_function/drv_src/drv_caller/drv_caller.c
<pre>
...
extern int export_hello(void);
...
export_hello();
...
</pre>

4. `app_a` set ioctl to `drv_callee.ko` to trigger the test: in the code /driver_export_function/app_src/app_a/app_a.c
<pre>
...
ioctl(file_desc, IOCTL_SET_MSG, message);
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>
2. set LD_LIBRARY_PATH environment variable to export shared library path.
in the directory "driver_export_function", then run below command.
<pre>$ export LD_LIBRARY_PATH=$(pwd)/build</pre>
3. check `build` directory and find out build result 
<pre>
app_a - application
drv_callee.sh, drv_caller.sh - script for install and uninstall driver
drv_callee.ko, drv_caller.ko - driver
</pre>
4. install driver drv_callee.ko and drv_caller.ko
<pre>
$ drv_callee.sh install
$ drv_caller.sh install
</pre>

5. run app_a to test
<pre>$ app_a </pre>

6. uninstall drivers
<pre>
$ drv_caller.sh uninstall
$ drv_callee.sh uninstall
</pre> 

7. remove all build result
<pre>
$ mk.sh clean
</pre>


