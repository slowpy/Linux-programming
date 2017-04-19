#include <iostream>
#include <string>

#include "cat.hh"

using namespace std;

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

std::string ECC::get_ecdh_key(const std::string & in_Key, const std::string & in_KeyFormat, const std::string & ret_KeyFormat)
{
    //cout << "ECC::get_ecdh_key" << endl;
    return "secret key: format(" + ret_KeyFormat + ")";
}

std::string ECC::encrypt(const std::string & ephemeralCurveName, const std::string & plaintext, const std::string & Key )
{
    //cout << "ECC::encrypt" << endl;
    return "encrypted text";

}

std::string ECC::decrypt(const std::string & ephemeralCurveName, const std::string & ciphertext, const std::string & Key)
{
    return "decrypted text";
}

std::string ECC::sign(const std::string & signatureType, const std::string & msg, const std::string & signatureFormat)
{
   return "signature, format:" + signatureFormat;
}

std::string ECC::get_signature(const std::string & signatureFormat)
{
   return "signature, format:" + signatureFormat;
}

std::string ECC::verify(const std::string & curveName, const std::string & key, const std::string & signature, const std::string & msg)
{
   return "true";
}
