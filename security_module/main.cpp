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
    ECC ecc(curveName, kdfName, hmacName, cipherName);
    cout << "ecc.speak = " << ecc.speak() << endl;
    return 0;
}
