#include <string>


/*********************************************************************************************************************/
/* SecureElement class                                                                                               */
/*********************************************************************************************************************/

class SecureElement
{
public:
    /*SecureElement() : constructor*/
    SecureElement();

    /*take_ownership(): take TPM2.0 ownership 
      input parameters:
        password : password to take ownership
      return value:
        "success" or "fail"
    */
    std::string take_ownership(const std::string & password);

    /*set_ownership(): set TPM2.0 ownership password
      input parameters:
        password          : password to set ownership
        confirmedPassword : password again to confirm
      return value:
        "success" or "fail"
    */
    std::string set_ownership(const std::string & password);

    /*app_secure_boot(): enable/disable application secure boot
      input parameters:
        enable : "true" for enable, "false" for disable
      return value:
        "success" or "fail"
    */
    std::string app_secure_boot(const std::string & enable);

    /*set_app_secure_boot_param(): set application secure boot parameters
      input parameters:
        app_list        : application list (e.g. "app1;app2;app3")
        app_config_list : application config list (e.g. "app1_config;app2_config;app3_config" )
      return value:
        "success" or "fail"
    */ 
    std::string set_app_secure_boot_param(const std::string & app_list, const std::string & app_config_list);

    /*store_data(): store data in secure element (TPM2.0 chip)
      input parameters:
        area               :  support "public", "sensitive" (TPM2.0 spec: sensitive area data is encrypted)
        encryption_type    :  support "AES-256", "RSA-2048", "ECC-256"
        name               :  name as index for storage 
        content            :  content for encryption if area is sensitive (e.g. content may be SIM-PIN, x.509 certificate, HMAC...)
      return value:
        "success" or "fail"
    */ 
    std::string store_data(const std::string & area, const std::string & encryption_type, const std::string & name, const std::string & content);

    /*update_data(): update data in secure element (TPM2.0 chip) storage area
      input parameters:
        area               :  support "public", "sensitive" (TPM2.0 spec: sensitive area data is encrypted)
        encryption_type    :  support "AES-256", "RSA-2048", "ECC-256"
        name               :  name as index for storage 
        content            :  content for encryption if area is sensitive (e.g. content may be SIM-PIN, x.509 certificate, HMAC...)
      return value:
        "success" or "fail"
    */ 
    std::string update_data(const std::string & area, const std::string & encryption_type, const std::string & name, const std::string & content);

    /*get_data(): get data from secure element (TPM2.0 chip)
      input parameters:
        area               :  support "public", "sensitive" (TPM2.0 spec: sensitive area data is encrypted)
        encryption_type    :  support "AES-256", "RSA-2048", "ECC-256"
        name               :  name as index for storage
      return value:
        data content
    */ 
    std::string get_data(const std::string & area, const std::string & encryption_type, const std::string & name);

    /*generate_true_random_number(): generate true random number
      input parameters:
        length         :  random number length with bytes
        format         :  random number format (support "HEX")
      return value:
        random number with specified length
    */ 
    std::string generate_true_random_number(const std::string & length, const std::string & format);

    /*generate_session_key(): generate session key (symmetric key)
      input parameters:
        length         :  session key with bits
        format         :  random number format (support "HEX")
      return value:
        session key with specified length
    */ 
    std::string generate_session_key(const std::string & length, const std::string & format);  
};

/*********************************************************************************************************************/
/* HASH class                                                                                                        */
/*********************************************************************************************************************/

class HASH
{
public:
    /*HASH(): HASH() constroctor use input parameter to decide hash scheme
      input parameters: 
        hashScheme : support SHA-1, SHA-2(support SHA-224, SHA-256, SHA-384, SHA-512)  
    */
    HASH(const std::string & hashScheme);
  
    /*get_hash(): caculate message hash value
      input parameters:
        msg         : message to caculate hash value
        hashForamt  : support "HEX" format
      return value:
        message hash value. 
    */
    std::string get_hash(const std::string & msg, const std::string & hashFormat);

    /*get_hmac(): caculate message hash value
      input parameters:
        msg         : message to caculate hash value
        key         : key to caculate hash value
        hashForamt  : support "HEX" format
      return value:
        message hash value. 
    */
    std::string get_hmac(const std::string & msg, const std::string & key, const std::string & hashFormat);
};

/*********************************************************************************************************************/
/* AES class                                                                                                         */
/*********************************************************************************************************************/

class AES
{
public:
    /*AES(): AES constructor use input parameters to generate key and use cipherScheme to encrypt/decrypt
      input parameters: 
        keyLength    : key length with bits
        cipherScheme : support CBC, CFB, OFB 
        
    */
    AES(const std::string & keyLength, const std::string & cipherScheme);

    /*get_key(): get key which is generated from AES constructor
      input parameters:
        format: support "HEX"
      return value:
        key with specified format.   
    */
    std::string get_key(const std::string & format);

    /*encrypt(): using input key to encrypt plaintext and generate ciphertext
      input parameters:
        plaintext         : the content for encryption
        Key               : Key is used to encrypt plaintext ( support "HEX" format)
      return value:
        ciphertext which is encrypted plaintext by Key. 
    */
    std::string encrypt(const std::string & plaintext, const std::string & Key);

    /*decrypt(): using key to decrypt ciphertext and generate plaintext
      input parameters:
        ciphertext        : encrypted contents for decryption.
        Key               : Key is used to decrypt ciphertext (support PEM, HEX format)
      return value:
        plaintext which is decrypted by key. 
    */
    std::string decrypt(const std::string & ciphertext, const std::string & Key );
};

/*********************************************************************************************************************/
/* RSA class                                                                                                         */
/*********************************************************************************************************************/

class RSA
{
public:
    /*RSA(): RSA constructor use input parameters to generate private/public key
      input parameters: 
        keyLength : key length with bits
        
    */
    RSA(const std::string & keyLength);

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
        plaintext         : the content for encryption
        Key               : Key is used to encrypt plaintext ( support PEM, HEX format)
        paddingType       : support PKCS1 and OAEP
      return value:
        ciphertext which is encrypted plaintext by Key. 
    */
    std::string encrypt(const std::string & plaintext, const std::string & Key, const std::string & paddingType);

    /*decrypt(): using private key to decrypt ciphertext and generate plaintext
      input parameters:
        cipherText        : encrypted contents for decryption.
        Key               : Key is used to decrypt ciphertext (support PEM, HEX format)
        paddingType       : support PKCS1 and OAEP
      return value:
        plaintext which is decrypted by key. 
    */
    std::string decrypt(const std::string & ciphertext, const std::string & Key, const std::string & paddingType);

    /*sign(): use RSA() generated private key to sign message
      input parameters:
        signatureType   : support "RSAwithSHA1", "RSAwithSHA256"
        key             : key to verify signature. support "PEM","HEX" format
        msg             : message to be signed
        signatureFormat : generated signature format. support "HEX"
      return value:
        signature with specified format
    */
    std::string sign(const std::string & signatureType, const std::string & key, const std::string & msg, const std::string & signatureFormat);

    /*verify(): verify signature for specified message
      input parameters:
        signatureType   : support "RSAwithSHA1", "RSAwithSHA256"
        key             : key to verify signature. support "PEM","HEX" format
        signature       : signature for verification. support "HEX" format
        msg             : message for signature verification 
      return value:
        true or false       
    */
    std::string verify(const std::string & signatureType, const std::string & key, const std::string & signature, const std::string & msg);
};

/*********************************************************************************************************************/
/* ECC class                                                                                                         */
/*********************************************************************************************************************/

class ECC
{
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
        Key               : Key is used to encrypt plaintext ( support PEM, HEX format)
      return value:
        ciphertext which is encrypted plaintext by Key. 
    */
    std::string encrypt(const std::string & ephemeralCurveName, const std::string & plaintext, const std::string & Key);

    /*decrypt(): using private key to decrypt ciphertext and generate plaintext
      input parameters:
        ephemeralCurveName: support "secp256k1", "sect571r1"  (default: secp256k1)
        cipherText        : encrypted contents for decryption.
        Key               : Key is used to decrypt ciphertext (support PEM, HEX format)
      return value:
        plaintext which is decrypted by key. 
    */
    std::string decrypt(const std::string & ephemeralCurveName, const std::string & ciphertext, const std::string & Key);

    /*sign(): use ECC() generated private key to sign message
      input parameters:
        signatureType   : support "ECDSA"
        key             : key to sign message
        msg             : message to be signed
        signatureFormat : generated signature format
      return value:
        signature with specified format
    */
    std::string sign(const std::string & signatureType, const std::string & key, const std::string & msg, const std::string & signatureFormat);

    /*get_signature(): get signature from sign() function
      input parameters:
        signatureFormat: specifed signature format. support "HEX", "DER"
      return value:
        signature with specified format
    */
    std::string get_signature(const std::string & signatureFormat);

    /*verify(): verify signature for specified message
      input parameters:
        curveName : support "secp256k1", "sect571r1"
        key       : key to verify signature. support "PEM","HEX" format
        signature : signature for verification. support "DER", "HEX" format
        msg       : message for signature verification 
      return value:
        true or false       
    */
    std::string verify(const std::string & curveName, const std::string & key, const std::string & signature, const std::string & msg);

    /*get_ecdh_key(): get ECDH shared secret key
      input parameters:
        in_Key: the peer key used to generate shared secret key
        ret_KeyFormat: shared secret key format
      return value:
        shared secret key with specified format
    */
    std::string get_ecdh_key(const std::string & in_Key, const std::string & ret_KeyFormat);

};
