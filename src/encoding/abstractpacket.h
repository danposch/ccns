#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H

#include "ipacket.h"
#include "binarybuffer.h"
#include "name.h"

namespace ccns
{
    namespace encoding
    {
        class AbstractPacket : public IPacket
        {
        public:
            AbstractPacket(int type, const util::Name &name);

            int getType();

            util::Name getName();

            int prefixMatch(const std::string &name);

            virtual ccns::util::BinaryBuffer serialize();

        protected:

            int packetType;
            util::Name packetName;

        };
    }
}

#endif // ABSTRACTPACKET_H
