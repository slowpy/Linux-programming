#RSA pair key encrypt/decrypt Sample code
This sample demo:
* how to use RSA public key encrypt and private key decrypt plaintext
* how to use RSA private key encrypt and public key decrypt plaintext

# How to setup build code environment
1. install openssl for [generate public key and private key](https://github.com/ivan0124/Linux-programming/wiki/How-to-generate-RSA-public-and-private-keys%28PEM-format%29-with-openssl-%3F)
<pre>
$ sudo apt-get install openssl
</pre>

2. install openssl library and header file for compiliation. you will sea header files installed in `/usr/include/openssl`
<pre>
$ sudo apt-get libssl-dev
</pre>

#Code Description

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
lib_demo_a.so, lib_demo_b.so, lib_common.so - shared library
drv_hello.ko - driver
</pre>

3. run app_a to test. you will see some logs in the screen.
<pre>$ mk.sh test </pre>


4. remove all build result
<pre>$ mk.sh clean</pre> 


