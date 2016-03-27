# Hello Driver Sample
This is a driver sample code to demo: (test on Ubuntu 10.04)

1. How to add ioctl function in driver
2. How to communicate between user space application and driver.


# How To Test 
1.build code and install driver
<pre>
$ ./mk.sh build 
</pre>

2.run ioctl to test
<pre>
$ ./ioctl
</pre>

3.uninstall driver
<pre>
$ mk.sh clean
</pre>

4.check the printk() log by typing `dmesg`
![test result link](http://139.162.35.49/image/Linux-Programming/20160327_driver_iotcl_demo.png)
