#ifndef IDIGITALSIGNATURE_H
#define IDIGITALSIGNATURE_H

#include "idigest.h"
#include "binarybuffer.h"

namespace ccns
{
    namespace crypto
    {
        class IDigitalSignature
        {
        public:
            enum ISignatureType{DSA};

            virtual ~IDigitalSignature(){}

            virtual bool generateKeyPair(util::BinaryBuffer *pub_buffer, util::BinaryBuffer *priv_buf) = 0;
            virtual util::BinaryBuffer sign(const util::BinaryBuffer &data, const util::BinaryBuffer &priv_key, util::BinaryBuffer *signature_buf = NULL) = 0;
            virtual util::BinaryBuffer verify(const util::BinaryBuffer &data, const util::BinaryBuffer &pub_key, util::BinaryBuffer *signature_buf = NULL) = 0;
            virtual ISignatureType getType() = 0;
        };
    }
}

#endif // IDIGITALSIGNATURE_H
