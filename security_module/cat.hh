#include <string>

class Cat
{
    std::string _name;
public:
    Cat(const std::string & name);
    void speak();
};

class ECC
{
    std::string _name;
public:
    ECC(const std::string & curveName, const std::string & KDF_HASH,  \
        const std::string & HMAC_HASH, const std::string & CipherName);
    std::string get_private_key(const std::string & format);
    std::string get_public_key(const std::string & format);
    std::string get_ecdh_key(const std::string & format);
    std::string encrypt(const std::string & plainText, const std::string & peerPublicKey, const std::string & ephemCurveName);
};
