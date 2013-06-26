#ifndef IPACKETBUILDER_H
#define IPACKETBUILDER_H

#include "ipacket.h"
#include "binarybuffer.h"

namespace ccns
{
    namespace encoding
    {

        class IPacketBuilder
        {

        public:

            enum PacketBuilderType {InterestBuilder, ContentObjectBuilder};

            virtual void setDefaultSettings() = 0;
            virtual IPacket* createPacket(const std::string &name, util::BinaryBuffer data) = 0; // packet_data_t
            virtual IPacket* createPacket(const std::string &name) = 0;
        };
    }
}

#endif // IPACKETBUILDER_H
