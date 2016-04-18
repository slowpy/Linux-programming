#Driver signal to app sample code
This sample demo how to use semaphore to avoid race condition.

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
1. declare semaphore `nvram_sem`:
<pre>
...
static DECLARE_MUTEX(nvram_sem);
...
</pre>

2. using `init_MUTEX` to initialize `nvram_sem`:
<pre>
static int drv_caller_init(void) {
...
        init_MUTEX(&nvram_sem);
...
</pre>

3. use `down(&nvram_sem)` and `up(&nvram_sem)` to protect race condition:
<pre>
...
	case IOCTL_SET_MSG:
		down(&nvram_sem);
                 "this area is protected from race condition"
        up(&nvram_sem);
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>
2. check `build` directory and find out build result 
<pre>
app_a - application which set ioctl to drv_caller.ko
app_b - application which set ioct to drv_caller.ko
drv_caller.ko - driver which send signal to app_a
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

4. type `mk.sh test` to test, until see test finish log.
<pre>$ mk.sh test </pre>
you will see below logs
![test result link](http://139.162.35.49/image/Linux-Programming/driver_semaphore_1.png)

5. type `dmesg` to see logs:
![test result link](http://139.162.35.49/image/Linux-Programming/driver_semaphore_2.png) 

6. uninstall drivers
<pre>
$ mk.sh uninstall
</pre>
type `dmesg`, you will see below logs
<pre>
drv_caller: exit
</pre>

7. remove all build result
<pre>
$ mk.sh clean
</pre>


