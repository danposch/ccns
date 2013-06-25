#ifndef IPACKETBUILDER_H
#define IPACKETBUILDER_H

#include "ipacket.h"

namespace ccns
{
    namespace encoding
    {

        class IPacketBuilder
        {

        public:

            enum PacketBuilderType {InterestBuilder, ContentObjectBuilder};

            virtual void setDefaultSettings() = 0;
            virtual IPacket* createPacket(const std::string &name, unsigned char* blob) = 0; // packet_data_t
            virtual IPacket* createPacket(const std::string &name) = 0;
        };
    }
}

#endif // IPACKETBUILDER_H
