# Hello Driver Sample
This is a driver sample code. (For Ubuntu test)

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
3.uninstall driver
<pre>
$ sudo rmmod hello
</pre>
