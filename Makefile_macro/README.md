#Makefile macro Sample code
This sample demo how to use $@, $<, $?, $* in Makefile.

#Code Description
1. show $@, $<, $*, $? value when compile c file to object: [Makefile](https://github.com/ivan0124/Linux-programming/blob/master/Makefile_macro/Makefile)
<pre>
...
.c.o:
	    gcc -c $<
	    $(warning "$$@ =$@")
	    $(warning "$$< =$<")
	    $(warning "$$* =$*")
	    $(warning "$$? =$?")
...
</pre>

2. show $@, $<, $*, $? value when compile target app_a: [Makefile](https://github.com/ivan0124/Linux-programming/blob/master/Makefile_macro/Makefile)
<pre>
...
app_a: $(OBJS)
	    gcc $? -o $@
	    $(warning "app_a $$@=$@")
	    $(warning "app_a $$<=$<")
	    $(warning "app_a $$*=$*")
	    $(warning "app_a $$?=$?")
...
</pre>

#How to test
1. build code
<pre>$ make</pre>
you will see the build message as below
![result link](http://139.162.35.49/image/Linux-Programming/Makefile_macro_20160415.png)

2. remove all build result
<pre>$ make clean</pre> 


