#ifndef DSA_H
#define DSA_H

#include <stdlib.h>
#include "cryptopp/dsa.h"
#include "cryptopp/osrng.h"
#include "cryptopp/queue.h"
#include <cryptopp/filters.h>

#include "abstractdigitalsignature.h"
#include "cryptoppdigest.h"

#define DSA_KEY_SIZE 1024

namespace ccns
{
    namespace crypto
    {
        class DSA : public AbstractDigitalSignature
        {
        public:
            DSA(ISignatureType type);

            bool generateKeyPair(util::BinaryBuffer *pub_buffer, util::BinaryBuffer *priv_buffer);
            util::BinaryBuffer sign(const util::BinaryBuffer &data, const util::BinaryBuffer &priv_key, util::BinaryBuffer *signature_buf = NULL);
            bool verify(const util::BinaryBuffer &data, const util::BinaryBuffer &pub_key, const util::BinaryBuffer signature_buf);

        protected:
            util::BinaryBuffer saveKey(CryptoPP::CryptoMaterial *key);
            bool loadKey(const util::BinaryBuffer &data, CryptoPP::CryptoMaterial *key);
        };
    }
}
#endif // DSA_H
