#ifndef ABSTRACTDIGEST_H
#define ABSTRACTDIGEST_H

#include "idigest.h"

namespace ccns
{
    namespace crypto
    {
        class AbstractDigest : public IDigest
        {
        public:
            AbstractDigest(IDigestType type);

            virtual ~AbstractDigest(){}

            virtual IDigestType getType();

            virtual util::BinaryBuffer computeDigest(util::BinaryBuffer &buffer) = 0;

            virtual size_t getDigestLength() = 0;

            virtual void add(unsigned char *data, size_t length);
            virtual void add(const util::BinaryBuffer &buffer);

            virtual void reset();
            virtual util::BinaryBuffer finialize() = 0;

        protected:
                IDigestType digestType;
                util::BinaryBuffer buf;
        };
    }
}
#endif // ABSTRACTDIGEST_H
