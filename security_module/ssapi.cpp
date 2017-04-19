#include <iostream>
#include <string>

#include "ssapi.hh"

using namespace std;

/*********************************************************************************************************************/
/* SecureElement class                                                                                               */
/*********************************************************************************************************************/

SecureElement::SecureElement()
{
    cout << "SecureElement()" << endl;
}

std::string SecureElement::app_secure_boot(const std::string & enable)
{
    cout << "SecureElement::app_secure_boot()" << endl;
    return "success";
}

std::string SecureElement::set_app_secure_boot_param(const std::string & app_list, const std::string & app_config_list)
{
    cout << "SecureElement::set_app_secure_boot_param()" << endl;
    return "success";
   
}

std::string SecureElement::store_data(const std::string & area, const std::string & encryption_type, const std::string & name, const std::string & content)
{
    cout << "SecureElement::store_data()" << endl;
    return "success";
}

std::string SecureElement::update_data(const std::string & area, const std::string & encryption_type, const std::string & name, const std::string & content)
{
    cout << "SecureElement::update_data()" << endl;
    return "success";
}

std::string SecureElement::get_data(const std::string & area, const std::string & encryption_type, const std::string & name)
{
    cout << "SecureElement::get_data()" << endl;
    return "data_content";

}

std::string SecureElement::generate_true_random_number(const std::string & length, const std::string & format)
{
    cout << "SecureElement::generate_true_random_number()" << endl;
    return "random_number";
}

std::string SecureElement::generate_session_key(const std::string & length, const std::string & format)
{
    cout << "SecureElement::generate_session_key()" << endl;
    return "session key";
}

/*********************************************************************************************************************/
/* HASH class                                                                                                        */
/*********************************************************************************************************************/
HASH::HASH(const std::string & hashScheme)
{
    cout << "HASH  = " << hashScheme << endl;
}

std::string HASH::get_hash(const std::string & msg, const std::string & hashFormat)
{
    cout << "HASH: HASH format(" + hashFormat + ")" << endl;
    return "HASH: HASH format(" + hashFormat + ")";
}

std::string HASH::get_hmac(const std::string & msg, const std::string & key, const std::string & hashFormat)
{
    cout << "HASH: HMAC format(" + hashFormat + ")" << endl;
    return "HASH: HMAC format(" + hashFormat + ")";
}

/*********************************************************************************************************************/
/* AES class                                                                                                         */
/*********************************************************************************************************************/
AES::AES(const std::string & keyLength, const std::string & cipherScheme)
{
    cout << "AES key length = " << keyLength << endl;
}

std::string AES::get_key(const std::string & format)
{
    cout << "AES key: format(" + format + ")" << endl;
    return "AES key: format(" + format + ")";
}

std::string AES::encrypt(const std::string & plaintext, const std::string & Key)
{
    cout << "AES:encrypted text" << endl;
    return "encrypted text";
}

std::string AES::decrypt(const std::string & ciphertext, const std::string & Key )
{
    cout << "AES: decrypt text" << endl;
    return "decrypted text";
}

/*********************************************************************************************************************/
/* RSA class                                                                                                         */
/*********************************************************************************************************************/

RSA::RSA(const std::string & keyLength)
{
    cout << "RSA key length = " << keyLength << endl;
}

std::string RSA::get_private_key(const std::string & format)
{
    cout << "RSA: private key: format(" + format + ")" << endl;
    return "RSA: private key: format(" + format + ")";
}

std::string RSA::get_public_key(const std::string & format)
{
    cout << "RSA: public key: format(" + format + ")" << endl;
    return "RSA: public key: format(" + format + ")";
}

std::string RSA::encrypt(const std::string & plaintext, const std::string & Key, const std::string & paddingType)
{
    cout << "RSA:encrypted text" << endl;
    return "encrypted text";

}

std::string RSA::decrypt(const std::string & ciphertext, const std::string & Key, const std::string & paddingType)
{
    cout << "RSA: decrypt text" << endl;
    return "decrypted text";
}

std::string RSA::sign(const std::string & signatureType, const std::string & key, const std::string & msg, const std::string & signatureFormat)
{

    cout << "RSA: sign message" << endl;
    return "RSA signature";
}

std::string RSA::verify(const std::string & signatureType, const std::string & key, const std::string & signature, const std::string & msg)
{
    cout << "RSA: verify signature" << endl;
    return "true";
}



/*********************************************************************************************************************/
/* ECC class                                                                                                         */
/*********************************************************************************************************************/

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

std::string ECC::get_ecdh_key(const std::string & in_Key, const std::string & ret_KeyFormat)
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

std::string ECC::sign(const std::string & signatureType, const std::string & key, const std::string & msg, const std::string & signatureFormat)
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
