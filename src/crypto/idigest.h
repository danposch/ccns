#ifndef IDIGEST_H
#define IDIGEST_H

#include "binarybuffer.h"

namespace ccns
{
    namespace crypto
    {
        class IDigest
        {
         public:
            enum IDigestType{Cryptopp_SHA1, Cryptopp_SHA_256, Cryptopp_SHA_384, Cryptopp_SHA_512,
                             Cryptopp_Whirlpool, Cryptopp_MD5, Cryptopp_MD4, Cryptopp_Tiger,
                             Cryptopp_RIPEMD320, Cryptopp_RIPEMD256, Cryptopp_RIPEMD160, Cryptopp_RIPEMD128,
                             Cryptopp_SHA3_224, Cryptopp_SHA3_256, Cryptopp_SHA3_384, Cryptopp_SHA3_512};

            virtual ~IDigest(){}

            virtual IDigestType getType() = 0;
            virtual size_t getDigestLength() = 0;

            virtual util::BinaryBuffer computeDigest(util::BinaryBuffer &buffer) = 0;

            virtual void add(unsigned char* data, size_t length) = 0;
            virtual void add(const util::BinaryBuffer &buffer) = 0;

            virtual void reset() = 0;
            virtual util::BinaryBuffer finialize() = 0;

        };
    }
}
#endif // IDIGEST_H
