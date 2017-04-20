#include <iostream>
#include <string>
#include "ssapi.hh"

using std::cout;using std::endl;using std::string;
int main()
{
    /*********************************************************************************************************************/
    /* SecureElement class scenario                                                                                      */
    /*********************************************************************************************************************/
    SecureElement TPM20;
    TPM20.take_ownership("123456");
    TPM20.set_ownership("654321");
    TPM20.app_secure_boot("ture");
    TPM20.set_app_secure_boot_param("app1;app2;app3","app1_config;app2_config;app3_config");
    TPM20.store_data("sensitive", "AES-256", "SIM-PIN", "123456");
    TPM20.update_data("sensitive", "AES-256", "SIM-PIN", "123456");
    TPM20.get_data("sensitive", "AES-256", "SIM-PIN");
    TPM20.generate_true_random_number("20", "HEX");
    TPM20.generate_session_key("20", "HEX");

    /*********************************************************************************************************************/
    /* HASH class scenario                                                                                               */
    /*********************************************************************************************************************/
    HASH hash_alice("SHA-256");

    string test_msg = "test message";
    string key = "123456";
    hash_alice.get_hash(test_msg,"HEX");
    hash_alice.get_hmac(test_msg, key, "HEX");

    /*********************************************************************************************************************/
    /* AES class scenario                                                                                                */
    /*********************************************************************************************************************/
     AES aes_alice("256","CBC");
     string aes_key = aes_alice.get_key("HEX");

     /*AES encryption/decryption
       step1: using aes_key to encrypt aes_msg and generate aes_ciphertext
       step2: using aes_key to decrypt aes_ciphertext and generate aes_plaintext
       step3: aes_plaintext and aes_msg is identical.
     */
     string aes_msg = "aes_test_msg";
     string aes_ciphertext = aes_alice.encrypt(aes_msg, aes_key);
     string aes_plaintext  = aes_alice.decrypt(aes_ciphertext, aes_key);

    /*********************************************************************************************************************/
    /* RSA class scenario                                                                                                */
    /*********************************************************************************************************************/
    RSA rsa_alice("2048");
    string rsa_msg = "rsa_test_msg";
    string rsa_prvkey = rsa_alice.get_private_key("PEM");
    string rsa_pubkey = rsa_alice.get_public_key("PEM");

    /*RSA encryption/decryption
      step1: using RSA public key to encrypt "rsa_test_msg"
      step2: using RSA private key to decrytp rsa_ciphertext
             then can get plaintext is "rsa_test_msg"
    */
    string rsa_ciphertext = rsa_alice.encrypt(rsa_msg, rsa_pubkey, "OAEP" );
    string rsa_plaintext = rsa_alice.decrypt(rsa_ciphertext, rsa_prvkey, "OAEP" );

    /*RSA sign message and verify signature
      step1: use RSA public key to sign rsa_msg and get rsa_signature
      step2: use RSA private key, signature, rsa_msg to verify this signature  
    */
    string rsa_signature = rsa_alice.sign("RSAwithSHA256", rsa_pubkey, rsa_msg, "HEX");
    rsa_alice.verify("RSAwithSHA256", rsa_prvkey, rsa_signature, rsa_msg);

    /*********************************************************************************************************************/
    /* ECC class scenario                                                                                                */
    /*********************************************************************************************************************/

    /*ECC class constructor generate key pair (private key/public key)
	  support below function:
	  ECIES(Elliptic Curve Integrated Encryption Scheme): Encryption/Decryption
	  ECDSA(Elliptic Curve Digital Signature Algorithm) : Signature
	  ECDH(Elliptic curve Diffie–Hellman)               : Key agreement
    */
    ECC alice("secp256k1", "KDF2_SHA_512", "HMAC_SHA_256", "AES_256_CBC");
    ECC bob("secp571r1", "KDF2_SHA_512", "HMAC_SHA_256", "AES_256_CBC");
    cout << "alice.get_private_key => " << alice.get_private_key( "PEM" ) << endl;
    cout << "alice.get_public_key => " << alice.get_public_key( "PEM" ) << endl; 

    /*ECIES: encryption and decryption
      step1: alice encrypt plaintext
      step2: bob can decrypt ciphertext of alice.
    */
    string alice_cipherText = alice.encrypt("secp571r1", "Hello Bob", bob.get_public_key("PEM"));
    cout << "alice cipherText => " << alice_cipherText << endl;
    string bob_decrypteText = bob.decrypt("secp571r1", alice_cipherText, bob.get_private_key("PEM"));
    cout << "bob.decrypt => " << bob_decrypteText << endl;

    /*ECDSA: sign message and verify signature
      step1: bob use its' private key to sign message and generate signature.
      step2: alice2 use bob's public key to verify bob's signature
    */
    ECC alice2("secp256k1", "KDF2_SHA_512", "HMAC_SHA_256", "AES_256_CBC");
    string message = "Hello Alice";
    string signature = bob.sign("ECDSA",bob.get_private_key("PEM"), message, "DER");
    cout << "bob.sign = " << signature << endl;
    cout << "bob.get_signature = " << bob.get_signature("DER") << endl;
    string verify_result = alice2.verify("spcp571r1", bob.get_public_key("PEM"), bob.get_signature("DER"), message);
    cout << "verify result = " << verify_result << endl;

    /*ECDH : key agreement
      step1: alice3 use bob's public key to get secret key: "alice3_secretKey"
      step2: bob use alice3's public key to get secret key: "bob_secretKey"
      step3: "alice3_secretKey" and "bob_secretKey" must be identical.
    */
    ECC alice3("secp571r1", "KDF2_SHA_512", "HMAC_SHA_256", "AES_256_CBC");
    string alice3_secretKey = alice3.get_ecdh_key(bob.get_public_key("PEM"), "HEX");
    string bob_secretKey = bob.get_ecdh_key(alice3.get_public_key("PEM"), "HEX");
    cout << "alice3_secretKey => " << alice3_secretKey << endl;
    cout << "bob.secretKey => " << bob_secretKey << endl;


    return 0;
}
