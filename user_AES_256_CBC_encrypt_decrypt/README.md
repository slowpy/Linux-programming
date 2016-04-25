#AES 256 CBC(Chipher Block Chaining) encrypt/decrypt Sample code
This sample demo how to use AES 256 CBC to encrypt/decrypt plaintext. (256 means key length is 256 bits)

![result link](http://139.162.35.49/image/Linux-Programming/AES_256_CBC_encryption_20160422.png)

# How to setup build code environment
1. install openssl library and header file for compiliation. you will sea header files installed in `/usr/include/openssl`
<pre>
$ sudo apt-get libssl-dev
</pre>

#Code Description
1. include header files: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
#include < openssl/aes.h >
#include < openssl/rand.h >
</pre>

2. set AES key `keylength`=256 bits and `aes_key` contents: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
int main(int argc, char **argv)
{
       int keylength=256;
       unsigned char aes_key[256/8]={"12345678901234567890123456789012"};
...
</pre>

3. set test plaintext as `X` assigne to `aes_input` and `inputslength`=1: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
    size_t inputslength = 1;
    unsigned char aes_input[inputslength];
    memset(aes_input, 'X', inputslength);
...
</pre>
4. using AES blcok size is defined in `AES_BLOCK_SIZE` the value is `16`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)

5. get initial `iv_enc` for encryption: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
    RAND_bytes(iv_enc, AES_BLOCK_SIZE);
    memcpy(iv_dec, iv_enc, AES_BLOCK_SIZE);
...
</pre>

6. set output encryption buffer `enc_out`. for `inputslength`=1 (bytes), `encslength`=16 (bytes): [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
const size_t encslength = ((inputslength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
unsigned char enc_out[encslength];
unsigned char dec_out[inputslength];
</pre>

7. for openssl using, set key to structure AES_KEY `enc_key`, `aes_key` and `keylength` are defined in `step2`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(aes_key, keylength, &enc_key);
</pre>

8. encrypt the plaintext by using `AES_cbc_encrypt()` with `AES_ENCRYPT`.`enc_out` is defined in `step6`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
AES_cbc_encrypt(aes_input, enc_out, inputslength, &enc_key, iv_enc, AES_ENCRYPT);
...
</pre>

9. decrypt the ciphertext by using `AES_cbc_encrypt()` with `AES_DECRYPT`. `dec_out` and `encslength` are defined in `step6`. `iv_dec` is defined in `step5`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_AES_256_CBC_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
    AES_set_decrypt_key(aes_key, keylength, &dec_key);
    AES_cbc_encrypt(enc_out, dec_out, encslength, &dec_key, iv_dec, AES_DECRYPT);
...
</pre>

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
you will set the result like below:
![result link](http://139.162.35.49/image/Linux-Programming/AES_256_CBC_encryption_20160425.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


