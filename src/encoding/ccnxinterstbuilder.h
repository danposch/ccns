#ifndef CCNXINTERSTBUILDER_H
#define CCNXINTERSTBUILDER_H

#include <iostream>

#include "abstractpacketbuilder.h"
#include "ipacket.h"
#include "ccnxinterest.h"

namespace ccns
{
    namespace encoding
    {

        class CCNxInterstBuilder : public AbstractPacketBuilder
        {
        public:
            CCNxInterstBuilder();

            IPacket* createPacket(const std::string &name, unsigned char*);
            IPacket* createPacket(const std::string &name);
        };
    }
}
#endif // CCNXINTERSTBUILDER_H
