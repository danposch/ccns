#ifndef IKEYSTORE_H
#define IKEYSTORE_H

#include "binarybuffer.h"

namespace ccns
{
    namespace crypto
    {
        class IKeyStore
        {
        public:
            virtual ~IKeyStore(){}

            virtual ICipherType getType() = 0;

            virtual util::BinaryBuffer generateKey() = 0;
            virtual util::BinaryBuffer loadKey() = 0;
            virtual bool storeKey() = 0;

            virtual util::BinaryBuffer generateCertificate() = 0;
            virtual util::BinaryBuffer loadCertificate() = 0;
            virtual bool storeCertificate() = 0;
        };
    }
}
#endif // IKEYSTORE_H
