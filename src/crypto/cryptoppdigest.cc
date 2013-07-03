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
        case IDigest::Cryptopp_Whirlpool:
        {
            digest = new CryptoPP::Whirlpool;
            break;
        }
        case IDigest::Cryptopp_MD5:
        {
            digest = new CryptoPP::MD5;
            break;
        }
        case IDigest::Cryptopp_MD4:
        {
            digest = new CryptoPP::MD4;
            break;
        }
        case IDigest::Cryptopp_Tiger:
        {
            digest = new CryptoPP::Tiger;
            break;
        }
        case IDigest::Cryptopp_RIPEMD320:
        {
            digest = new CryptoPP::RIPEMD320;
            break;
        }
        case IDigest::Cryptopp_RIPEMD256:
        {
            digest = new CryptoPP::RIPEMD256;
            break;
        }
        case IDigest::Cryptopp_RIPEMD160:
        {
            digest = new CryptoPP::RIPEMD160;
            break;
        }
        case IDigest::Cryptopp_RIPEMD128:
        {
            digest = new CryptoPP::RIPEMD128;
            break;
        }
        case IDigest::Cryptopp_SHA3_224:
        {
        digest = new CryptoPP::SHA3_224;
        break;
        }
        case IDigest::Cryptopp_SHA3_256:
        {
        digest = new CryptoPP::SHA3_256;
        break;
        }
        case IDigest::Cryptopp_SHA3_384:
        {
        digest = new CryptoPP::SHA3_384;
        break;
        }
        case IDigest::Cryptopp_SHA3_512:
        {
        digest = new CryptoPP::SHA3_512;
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

size_t CryptoppDigest::getDigestLength()
{
    return digest->DigestSize();
}
