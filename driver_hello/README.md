# Hello Driver Sample
This is a driver sample code. (test on Ubuntu 10.04)

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

# How To Test 
1.Typing `make` to build code

2.install driver
<pre>
$ sudo insmod ./hello.ko
</pre>
3.check the printk() log by typing `dmesg`
you will see "<1>hello_driver: init" in log
4.uninstall driver
<pre>
$ sudo rmmod hello
</pre>
5.check the printk() log by typing `dmesg`
you will see "<1>hello_driver: exit" in log

