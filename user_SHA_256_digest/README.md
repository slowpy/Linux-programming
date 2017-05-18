#SHA 256 Sample code
This sample demo how to generate SHA 256 digest

# How to setup build code environment
1. install openssl library and header file for compiliation. you will sea header files installed in `/usr/include/openssl`
<pre>
$ sudo apt-get install libssl-dev
</pre>

#Code Description
1. include header files: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_SHA_256_digest/app_src/app_a/app_a.c)
<pre>
...
#include < openssl/sha.h >
</pre>

2. use `SHA256_Init()`, `SHA256_Update()` and `SHA256_Final()` to generate digest: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_SHA_256_digest/app_src/app_a/app_a.c)
<pre>
...
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, (unsigned char *)data, sizeof(data));
    SHA256_Final(results, &ctx);
...
</pre>


#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
</pre>

3. run `mk.sh test` to test.
<pre>$ mk.sh test </pre>
![result link](http://139.162.35.49/image/Linux-Programming/SHA_256_digest_20160425.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


