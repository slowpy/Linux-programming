#Driver timer Sample code
This sample demo how to setup driver timer.

#How to setup build code environment
1. install build code tools
<pre>
sudo apt-get install build-essential
</pre>
2. check wehether kernel header files exist.
<pre>
ls /lib/modules/$(uname -r)/build
</pre>
2. if kernel header files doesn't exist, try to install them.
<pre>
sudo apt-get install linux-headers-$(uname -r)
</pre>

#Code Description
1. setup timer to call callback function: in the code ./driver_timer/drv_src/drv_timer/drv_timer.c
<pre>
void my_timer_callback( unsigned long data )
{
...
       setup_timer(&my_timer, my_timer_callback, 0);
...
}
static int drv_timer_init(void) 
{
...
       setup_timer(&my_timer, my_timer_callback, 0);
...
}
</pre>


2. set timer interval to `1000` ms: in the code ./driver_timer/drv_src/drv_timer/drv_timer.c
<pre>
void my_timer_callback( unsigned long data )
{
...
       mod_timer(&my_timer, jiffies + msecs_to_jiffies(1000));
...
}
static int drv_timer_init(void) 
{
...
       mod_timer(&my_timer, jiffies + msecs_to_jiffies(1000));
...
}
</pre>

3. delete timer:
<pre>
static void drv_timer_exit(void) {
...
    del_timer(&my_timer);
...
}
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
drv_timer.ko - driver
drv_timer.sh - script to install or uninstall driver
</pre>

3. install driver.
<pre>$ mk.sh install</pre>
type `dmesg` to see below logs
<pre>
drv_timer: init
drv_timer: timer triggered(count=0)
drv_timer: timer triggered(count=1)
...
</pre>

4. uninstall driver
<pre>$ mk.sh uninstall</pre>
type `dmesg` to see below logs
<pre>
drv_timer: exit
</pre>

5. remove all build result
<pre>$ make clean</pre> 


