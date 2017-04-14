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
    std::string speak();
};
