#include <iostream>
#include <string>

#include "cat.hh"

using namespace std;

Cat::Cat(const string & name):_name(name){}
void Cat::speak()
{
    cout << "Meow~~~~~~~~! I'm " << _name << endl;
}


ECC::ECC(const string & curveName, const std::string & KDF_HASH,  \
         const std::string & HMAC_HASH, const std::string & CipherName)
{
    cout << "ECC::curveName = " << curveName << endl;
    cout << "ECC::KDF_HASH = " << KDF_HASH << endl;
    cout << "ECC::HAMC_HASH = " << HMAC_HASH << endl;
    cout << "ECC::CipherName = " << CipherName << endl;
}

std::string ECC::get_private_key(const std::string & format)
{
    //cout << "ECC::get_private_key" << endl;
    return "private key: format(" + format + ")";
}

std::string ECC::get_public_key(const std::string & format)
{
    //cout << "ECC::get_public_key" << endl;
    return "public key: format(" + format + ")";
}

std::string ECC::get_ecdh_key(const std::string & format)
{
    //cout << "ECC::get_ecdh_key" << endl;
    return "secret key: format(" + format + ")";
}

std::string ECC::encrypt(const std::string & plainText, const std::string & peerPublicKey, const std::string & ephemCurveName)
{
    //cout << "ECC::encrypt" << endl;
    return "encrypted text";

}

std::string ECC::decrypt(const std::string & encryptedText)
{
    return "decrypted text";
}
