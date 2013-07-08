#ifndef ICIPHER_H
#define ICIPHER_H

#include "binarybuffer.h"

namespace ccns
{
    namespace crypto
    {
        class ICipher
        {
        public:
            enum ICipherType{AES_128_CBC, AES_256_CBC};

            virtual ~ICipher(){}

            virtual ICipherType getType() = 0;

            virtual util::BinaryBuffer encrypt(const util::BinaryBuffer &in, util::BinaryBuffer *out = NULL) = 0;
            virtual util::BinaryBuffer decrypt(const util::BinaryBuffer &in, util::BinaryBuffer *out = NULL) = 0;

        };
    }
}
#endif // ICIPHER_H
