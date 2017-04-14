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

std::string ECC::speak()
{
    cout << "ECC~~~~~~~~! I'm " << _name << endl;
    return "12345";
}
