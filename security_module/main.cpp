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
    /*
    string curveName = "secp256k1";
    string kdfName = "KDF_SHA_512";
    string hmacName = "HMAC_SHA_256";
    string cipherName = "AES_256_CBC";
    string pemFormat = "PEM";
    string hexFormat = "HEX";
    */

    ECC alice("secp256k1", "KDF_SHA_512", "HMAC_SHA_256", "AES_256_CBC");
    ECC bob("secp256k1", "KDF_SHA_512", "HMAC_SHA_256", "AES_256_CBC");
    cout << "alice.get_private_key => " << alice.get_private_key( "PEM" ) << endl;
    cout << "alice.get_public_key => " << alice.get_public_key( "PEM" ) << endl;
    cout << "alice.get_ecdh_key => " << alice.get_ecdh_key("HEX") << endl;
    cout << "alice.encrypt => " << alice.encrypt("Hello Bob", bob.get_public_key("PEM"), "secp256k1" ) << endl;
    return 0;
}
