#include <string>


class ECC
{
    std::string _name;
public:
    /*ECC(): ECC constructor use input parameters to generate private/public key and support ECIES encryption/decryption
      input parameters: 
        curveName : support "secp256k1", "sect571r1"  (default: secp256k1)
        KDF_HASH  : support "KDF1_SHA256", "KDF1_SHA512", "KDF2_SHA256", "KDF2_SHA512"  (default: KDF2_SHA512)
        HMAC_HASH : support "HMAC_SHA256", "HMAC_SHA512" (default: HMAC_SHA512)
        CipherName: support "AES_256_CBC", "AES_256_OFB", "AES_256_CFB" (default: AES_256_CBC)
    */
    ECC(const std::string & curveName, const std::string & KDF_HASH,  \
        const std::string & HMAC_HASH, const std::string & CipherName);

    /*get_private_key(): get private key which is generated from ECC constructor
      input parameters:
        format: support "PEM", "HEX"
      return value:
        private key with specified format.   
    */
    std::string get_private_key(const std::string & format);

    /*get_public_key(): get public key which is generated from ECC constructor
      input parameters:
        format: support "PEM", "HEX"
      return value:
        private key with specified format.   
    */
    std::string get_public_key(const std::string & format);

    /*encrypt(): using input key to encrypt plaintext and generate ciphertext
      input parameters:
        ephemeralCurveName: support "secp256k1", "sect571r1"  (default: secp256k1)
        plaintext         : the content for encryption
        Key               : Key is used to encrypt plaintext
      return value:
        ciphertext which is encrypted plaintext by Key. 
    */
    std::string encrypt(const std::string & ephemeralCurveName, const std::string & plaintext, const std::string & Key);

    /*decrypt(): using private key to decrypt ciphertext and generate plaintext
      input parameters:
        ephemeralCurveName: support "secp256k1", "sect571r1"  (default: secp256k1)
        cipherText: encrypted contents for decryption.
        Key               : Key is used to decrypt ciphertext
      return value:
        plaintext which is decrypted by key. 
    */
    std::string decrypt(const std::string & ephemeralCurveName, const std::string & ciphertext, const std::string & Key);

    //
    std::string sign(const std::string & signatureType, const std::string & msg, const std::string & signatureFormat);
    std::string get_signature(const std::string & signatureFormat);
    std::string verify(const std::string & curveName, const std::string & key, const std::string & signature, const std::string & msg);
    std::string get_ecdh_key(const std::string & in_Key, const std::string & in_KeyFormat, const std::string & ret_KeyFormat);

};
