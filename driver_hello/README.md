# Hello Driver Sample
This is a driver sample code.

1. Before build sample code, you need to install tools and header files:
For example in Ubuntu,
<pre>
$ sudo apt-get install build-essential linux-headers-$(uname -r)
</pre>

# How To Test
1.Typing `make` and see the message in screen
2.install driver
<pre>
$ sudo insmod ./hello.ko
</pre>
3.uninstall driver
<pre>
$ sudo rmmod hello
</pre>
