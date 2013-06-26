#ifndef CCNXCONTENTOBJECTBUILDER_H
#define CCNXCONTENTOBJECTBUILDER_H

#include "abstractpacketbuilder.h"
#include "ipacket.h"
#include "ccnxcontentobject.h"
#include "binarybuffer.h"

namespace ccns
{
    namespace encoding
    {

        class CCNxContentObjectBuilder : public AbstractPacketBuilder
        {
        public:
            CCNxContentObjectBuilder();

            IPacket* createPacket(const std::string &name, util::BinaryBuffer data);
        };
    }
}
#endif // CCNXCONTENTOBJECTBUILDER_H
