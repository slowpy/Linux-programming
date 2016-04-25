#AES 256 CBC(Chipher Block Chaining) encrypt/decrypt Sample code
This sample demo how to use AES 256 CBC to encrypt/decrypt plaintext. (256 means key length is 256 bits)

![result link](http://139.162.35.49/image/Linux-Programming/AES_256_CBC_encryption_20160422.png)

# How to setup build code environment
1. install openssl library and header file for compiliation. you will sea header files installed in `/usr/include/openssl`
<pre>
$ sudo apt-get libssl-dev
</pre>

#Code Description
1. include header files:
<pre>
...
#include <openssl/aes.h>
#include <openssl/rand.h>
</pre>

2. set AES key length as `256` bits and key contents:
<pre>
int main(int argc, char **argv)
{
       int keylength=256;
       unsigned char aes_key[256/8]={"12345678901234567890123456789012"};
...
</pre>

3.

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
lib_common.so - shared library
</pre>

3. run `mk.sh test` to test.
<pre>$ mk.sh test </pre>
![result link](http://139.162.35.49/image/Linux-Programming/RSA_20160422_1.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


