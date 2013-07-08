#ifndef ABSTRACTCIPHER_H
#define ABSTRACTCIPHER_H

#include "icipher.h"

namespace ccns
{
    namespace crypto
    {
        class AbstractCipher : public ICipher
        {
        public:
            AbstractCipher(ICipherType cipherType);
            virtual ~AbstractCipher(){}

            virtual ICipherType getType();

            virtual util::BinaryBuffer encrypt(const util::BinaryBuffer &in, util::BinaryBuffer *out = NULL);
            virtual util::BinaryBuffer decrypt(const util::BinaryBuffer &in, util::BinaryBuffer *out = NULL);

        protected:
            ICipherType cipherType;
        };
    }
}
#endif // ABSTRACTCIPHER_H
