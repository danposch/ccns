#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H

#include "ipacket.h"
#include "binarybuffer.h"

namespace ccns
{
    namespace encoding
    {
        class AbstractPacket : public IPacket
        {
        public:
            AbstractPacket(int type, const std::string &name);

            int getType();

            std::string getName();

            int prefixMatch(const std::string &name);

            virtual ccns::util::BinaryBuffer serialize();

        protected:

            int packetType;
            std::string packetName;

        };
    }
}

#endif // ABSTRACTPACKET_H
