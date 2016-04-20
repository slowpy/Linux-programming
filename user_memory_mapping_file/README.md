#Mapping files into memory Sample code
This sample demo how to use `mmap()` to mapping file to process memory address space.
![result link](http://139.162.35.49/image/Linux-Programming/user_memory_mapping_file_20160420_1.png)

# Code Description
1. using `open()` with `O_RDONLY` to get `fd` for read:
<pre>
...
fd = open("./test.txt", O_RDONLY);
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
tcp_client - application which send/receive tcp packets
tcp_server - application which send/receive tcp packets
lib_common.so - shared library
</pre>

3. type `mk.sh test` to test. 
<pre>$ mk.sh test </pre>
you can see test result like below:
![result link](http://139.162.35.49/image/Linux-Programming/user_tcp_client_server_20160420_1.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


