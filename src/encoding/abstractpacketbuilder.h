#ifndef ABSTRACTPACKETBUILDER_H
#define ABSTRACTPACKETBUILDER_H

#include "ipacketbuilder.h"
#include "ipacket.h"

namespace ccns
{
    namespace encoding
    {
        class AbstractPacketBuilder : public IPacketBuilder
        {
        public:
            AbstractPacketBuilder();

            virtual IPacket* createPacket(const std::string &name, unsigned char* blob);
            virtual IPacket* createPacket(const std::string &name);

            void setDefaultSettings();
        };
    }
}

#endif // ABSTRACTPACKETBUILDER_H
