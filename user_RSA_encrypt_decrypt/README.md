#RSA pair key encrypt/decrypt Sample code
This sample demo:
* how to use RSA public key encrypt and private key decrypt plaintext
* how to use RSA private key encrypt and public key decrypt plaintext

# How to setup build code environment
1. install openssl header file for compiler. you will files installed in `/usr/include/openssl`
<pre>
$ sudo apt-get libssl-dev
</pre>

#

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
lib_demo_a.so, lib_demo_b.so, lib_common.so - shared library
drv_hello.ko - driver
</pre>

3. install driver.
<pre>$ mk.sh install</pre>
type `dmesg` to see below logs
<pre>
drv_hello: init
</pre>

4. run app_a to test. you will see some logs in the screen.
<pre>$ mk.sh test </pre>


5. uninstall driver
<pre>$ mk.sh uninstall</pre>
type `dmesg` to see below logs
<pre>
drv_hello: exit
</pre>

6. remove all build result
<pre>$ mk.sh clean</pre> 


