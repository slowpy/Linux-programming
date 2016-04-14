#Driver /proc read/write Sample code
This sample demo how to implement /proc read/write function in the driver.

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
1. include header files: [drv_proc_rw.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_proc_rw/drv_src/drv_proc_rw/drv_proc_rw.c)
<pre>
...
#include <linux/proc_fs.h>
#include <linux/uaccess.h> //for copy_from_user(): in the code
...
</pre>

2. create `/proc/proc_rw_type` : [drv_proc_rw.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_proc_rw/drv_src/drv_proc_rw/drv_proc_rw.c)
<pre>
static int drv_proc_rw_init(void) {
...
        if ((proc_rw = create_proc_entry( "proc_rw_type", 0, NULL ))){
            proc_rw->read_proc = proc_rw_read_proc;
            proc_rw->write_proc = proc_rw_write_proc;
        }
...
}
</pre>

3. remove `/proc/proc_rw_type`: [drv_proc_rw.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_proc_rw/drv_src/drv_proc_rw/drv_proc_rw.c)
<pre>
static void drv_proc_rw_exit(void) {
...
        remove_proc_entry("proc_rw_type", NULL);
...
}
</pre>

4. implement `/proc/proc_rw_type` read function, variable `page` is buffer from user space: [drv_proc_rw.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_proc_rw/drv_src/drv_proc_rw/drv_proc_rw.c)
<pre>
static int proc_rw_read_proc (char *page, char **start, off_t off, int count,
			  int *eof, void *data_unused)
{
...
	    len = sprintf(page,"proc_rw_type=%s\n", g_proc_rw_type);
...
}
</pre>

5. implement `/proc/proc_rw_type` write function, copy user space `buffer` value to kernel space `g_proc_rw_type`: [drv_proc_rw.c](https://github.com/ivan0124/Linux-programming/blob/master/driver_proc_rw/drv_src/drv_proc_rw/drv_proc_rw.c)
<pre>
static int proc_rw_write_proc(struct file *file, const char *buffer, unsigned long count, void *data)
{
...
        if (copy_from_user(g_proc_rw_type, buffer, len))
        {
...
}
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
drv_proc_rw.ko - driver
drv_proc_rw.sh - script to install drv_proc_rw.ko driver
</pre>

3. install driver.
<pre>$ mk.sh install</pre>
type `dmesg` to see below logs
<pre>
drv_proc_rw: init
</pre>

4. read/write `/proc/proc_rw_type` by calling `mk.sh test`.
<pre>$ mk.sh test </pre>
you see test logs like below:

   ![result link](http://139.162.35.49/image/Linux-Programming/driver_proc_rw_20160414_1.png)

5. uninstall driver
<pre>$ mk.sh uninstall</pre>
type `dmesg` to see below logs
<pre>
drv_proc_rw: exit
</pre>

6. remove all build result
<pre>$ mk.sh clean</pre> 


