#ifndef CRYPTOPPDIGEST_H
#define CRYPTOPPDIGEST_H

#include <cryptopp/sha.h>
#include <cryptopp/filters.h>

#include "abstractdigest.h"
#include "idigest.h"

namespace ccns
{
    namespace crypto
    {
        class CryptoppDigest : public AbstractDigest
        {
        public:

            CryptoppDigest(IDigestType type);
            ~CryptoppDigest();

            util::BinaryBuffer computeDigest(util::BinaryBuffer &buffer);
            util::BinaryBuffer finialize();

        private:
            CryptoPP::HashTransformation *digest;

        };
    }
}

#endif // CRYPTOPPDIGEST_H
