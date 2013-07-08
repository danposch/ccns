#ifndef CRYPTOPPDIGEST_H
#define CRYPTOPPDIGEST_H

#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <cryptopp/whrlpool.h>
#include <cryptopp/ripemd.h>
#include <cryptopp/tiger.h>
#include <cryptopp/md5.h>
#include <cryptopp/md4.h>
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

            util::BinaryBuffer computeDigest(const util::BinaryBuffer &buffer);
            util::BinaryBuffer finialize();

            size_t getDigestLength();

        private:
            CryptoPP::HashTransformation *digest;

        };
    }
}

#endif // CRYPTOPPDIGEST_H
