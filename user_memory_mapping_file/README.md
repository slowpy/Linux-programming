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

2. using `fstat()` to get file information(sb.st_size, sb.st_mode...):
<pre>
...
    if ( fstat(fd, &sb) == -1 ){
...
</pre>

3. using `S_ISREG(sb.st_mode)` to check if the file is regular file
<pre>
...
    if (!S_ISREG(sb.st_mode)){
...
</pre>

4. using `mmap()` mapping file into process memory sapce and get address `p`:
<pre>
...
    p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
...
</pre>

5. using `putchar()` to print address `p` memory content:
<pre>
...
    for (len=0; len < sb.st_size; len++)
        putchar(p[len]);
...
</pre>

6. using `munmap()` to release addrss `p` memory:
<pre>
...
    if (munmap(p, sb.st_size) == -1){
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
mmap- application which demo mapping file into memory
lib_common.so - shared library
</pre>

3. type `mk.sh test` to test. 
<pre>$ mk.sh test </pre>
you can see test result like below:
![result link](http://139.162.35.49/image/Linux-Programming/user_memory_mapping_file_20160420_2.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


