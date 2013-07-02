#include "cryptoppdigest.h"

using namespace ccns::crypto;

CryptoppDigest::CryptoppDigest(IDigestType type) : AbstractDigest(type)
{
    switch(this->digestType)
    {
        case IDigest::Cryptopp_SHA1:
        {
            digest = new CryptoPP::SHA1;
            break;
        }
        case IDigest::Cryptopp_SHA_256:
        {
            digest = new CryptoPP::SHA256;
            break;
        }
        case IDigest::Cryptopp_SHA_384:
        {
            digest = new CryptoPP::SHA384;
            break;
        }
        case IDigest::Cryptopp_SHA_512:
        {
            digest = new CryptoPP::SHA512;
            break;
        }
        default:
        {
           digest = new CryptoPP::SHA1;
           break;
        }
    }
}

CryptoppDigest::~CryptoppDigest()
{
    if(digest != NULL)
        delete digest;
}

ccns::util::BinaryBuffer CryptoppDigest::finialize()
{
    return computeDigest(this->buf);
}

ccns::util::BinaryBuffer CryptoppDigest::computeDigest(util::BinaryBuffer &buffer)
{

    digest->Restart();
    digest->Update(buffer.data(), buffer.length());

    unsigned char* obuf = (unsigned char*)calloc(digest->DigestSize(), sizeof(unsigned char));
    digest->Final(obuf);

    ccns::util::BinaryBuffer ret(obuf, digest->DigestSize());
    free(obuf);

    return ret;
}
