#include "cryptlib.h"
#include "files.h"
#include "hex.h"
#include "sha.h"
#include "hmac.h"
using namespace CryptoPP;

#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    const byte m[] = {
        0x5, 0x8, 0xC, 0xE, 0x1, 0xE, 0x6, 0x0, 0x1, 0x1,
        0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x6, 0x4, 0x6, 0x1,
        0x7, 0x4, 0x6, 0x1, 0x0, 0x0, 0x0, 0x0};

    const byte k[] = {
        0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
        0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
        0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
        0x1, 0x1};

    HexEncoder hex(new FileSink(std::cout));

    HMAC<SHA1> hmac(k, sizeof(k));
    hmac.Update(m, sizeof(m));

    byte d[HMAC<SHA1>::DIGESTSIZE];
    hmac.Final(d);

    std::cout << "Message: ";
    hex.Put(m, sizeof(m));
    hex.MessageEnd();
    std::cout << std::endl;

    std::cout << "Digest: ";
    hex.Put(d, sizeof(d));
    hex.MessageEnd();
    std::cout << std::endl;

    return 0;
}
