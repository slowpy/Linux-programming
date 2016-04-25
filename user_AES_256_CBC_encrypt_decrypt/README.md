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
#include < openssl/aes.h >
#include < openssl/rand.h >
</pre>

2. set AES key `keylength`=256 bits and `aes_key` contents:
<pre>
int main(int argc, char **argv)
{
       int keylength=256;
       unsigned char aes_key[256/8]={"12345678901234567890123456789012"};
...
</pre>

3. set test plaintext as `X` assigne to `aes_input` and `inputslength`=`:
<pre>
...
    size_t inputslength = 1;
    unsigned char aes_input[inputslength];
    memset(aes_input, 'X', inputslength);
...
</pre>
4. using AES blcok size is defined in `AES_BLOCK_SIZE` the value is `16`

5. get initial `iv_enc` for encryption
<pre>
...
    RAND_bytes(iv_enc, AES_BLOCK_SIZE);
    memcpy(iv_dec, iv_enc, AES_BLOCK_SIZE);
...
</pre>

6. set output encryption buffer `enc_out`. for `inputslength`=1 (bytes), `encslength`=16 (bytes):
<pre>
...
const size_t encslength = ((inputslength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
unsigned char enc_out[encslength];
</pre>

7. for openssl using, set key to structure `AES_KEY`, key value and length is from `step2`:
<pre>
    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(aes_key, keylength, &enc_key);
</pre>

8. encrypt the plaintext and get ciphertext
<pre>
...
AES_cbc_encrypt(aes_input, enc_out, inputslength, &enc_key, iv_enc, AES_ENCRYPT);
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
![result link](http://139.162.35.49/image/Linux-Programming/RSA_20160422_1.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


