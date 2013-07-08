#ifndef DIGITALSIGNATUREFACTORY_H
#define DIGITALSIGNATUREFACTORY_H

#include "idigitalsignature.h"
#include "dsa.h"

namespace ccns
{
    namespace crypto
    {
        class DigitalSignatureFactory
        {
        public:
            static IDigitalSignature* getSignatureAlgorithm(ccns::crypto::IDigitalSignature::ISignatureType type);
        };
    }
}

#endif // DIGITALSIGNATUREFACTORY_H
