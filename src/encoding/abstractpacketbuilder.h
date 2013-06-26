#ifndef ABSTRACTPACKETBUILDER_H
#define ABSTRACTPACKETBUILDER_H

#include "ipacketbuilder.h"
#include "ipacket.h"
#include "binarybuffer.h"

namespace ccns
{
    namespace encoding
    {
        class AbstractPacketBuilder : public IPacketBuilder
        {
        public:
            AbstractPacketBuilder();

            virtual IPacket* createPacket(const std::string &name, util::BinaryBuffer data);
            virtual IPacket* createPacket(const std::string &name);

            void setDefaultSettings();
        };
    }
}

#endif // ABSTRACTPACKETBUILDER_H
