#ifndef ABSTRACTDIGITALSIGNATURE_H
#define ABSTRACTDIGITALSIGNATURE_H

#include "idigitalsignature.h"

namespace ccns
{
    namespace crypto
    {
         class AbstractDigitalSignature : public IDigitalSignature
        {
            public:
               AbstractDigitalSignature(ISignatureType sigType);
               virtual ~AbstractDigitalSignature(){}

               virtual bool generateKeyPair(util::BinaryBuffer *pub_buffer, util::BinaryBuffer *priv_buf) = 0;
               virtual util::BinaryBuffer sign(const util::BinaryBuffer &data,const util::BinaryBuffer &priv_key, util::BinaryBuffer *signature_buf = NULL) = 0;
               virtual util::BinaryBuffer verify(const util::BinaryBuffer &data,const util::BinaryBuffer &pub_key, util::BinaryBuffer *signature_buf = NULL) = 0;
               virtual ISignatureType getType();

         private:
               ISignatureType sigType;
        };
    }
}

#endif // ABSTRACTDIGITALSIGNATURE_H
