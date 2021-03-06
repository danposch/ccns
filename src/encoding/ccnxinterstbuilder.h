#ifndef CCNXINTERSTBUILDER_H
#define CCNXINTERSTBUILDER_H

#include <iostream>

#include "abstractpacketbuilder.h"
#include "ipacket.h"
#include "ccnxinterest.h"
#include "name.h"

namespace ccns
{
    namespace encoding
    {

        class CCNxInterstBuilder : public AbstractPacketBuilder
        {
        public:
            CCNxInterstBuilder();

            IPacket* createPacket(const util::Name &name, const util::BinaryBuffer&);
            IPacket* createPacket(const util::Name &name);

        protected:
            void initProperties();
        };
    }
}
#endif // CCNXINTERSTBUILDER_H
