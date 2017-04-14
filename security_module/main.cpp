#include <iostream>
#include <string>
#include "cat.hh"

using std::cout;using std::endl;using std::string;
int main()
{
    string name = "Felix";
    cout<< "Meet my cat~~~~~, " << name << "!" <<endl;
    Cat kitty(name);
    kitty.speak();
    //
    string curveName = "secp256k1";
    string kdfName = "KDF_SHA_512";
    string hmacName = "HMAC_SHA_256";
    string cipherName = "AES_256_CBC";
    string pemFormat = "PEM";
    string hexFormat = "HEX";

    ECC ecc(curveName, kdfName, hmacName, cipherName);
    cout << "ecc.get_private_key => " << ecc.get_private_key( pemFormat ) << endl;
    cout << "ecc.get_public_key => " << ecc.get_public_key( pemFormat ) << endl;
    cout << "ecc.get_ecdh_key => " << ecc.get_ecdh_key(hexFormat) << endl;
    return 0;
}
