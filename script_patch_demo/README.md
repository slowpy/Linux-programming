#Patch Demo Sample
This is a sample to demo how to create patch and patch files.

* create patch
<pre>
diff -ruN hello_old/ hello_new/ > hello.patch
</pre>

* patch by hello.patch
<pre>
patch -p1 < hello.patch
</pre>

# How To Test
Typing `test_patch.sh` and see the message in screen

![test result link](http://139.162.35.49/image/Linux-Programming/script_patch_2016-03-22_10.18.28.png)

