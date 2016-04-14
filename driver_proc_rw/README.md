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
you kernel logs like below:


5. uninstall driver
<pre>$ mk.sh uninstall</pre>
type `dmesg` to see below logs
<pre>
drv_proc_rw: exit
</pre>

6. remove all build result
<pre>$ mk.sh clean</pre> 


