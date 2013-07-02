#ifndef CCNXCONTENTOBJECTBUILDER_H
#define CCNXCONTENTOBJECTBUILDER_H

#include "abstractpacketbuilder.h"
#include "ipacket.h"
#include "ccnxcontentobject.h"
#include "binarybuffer.h"
#include "name.h"

namespace ccns
{
    namespace encoding
    {

        class CCNxContentObjectBuilder : public AbstractPacketBuilder
        {
        public:
            CCNxContentObjectBuilder();

            IPacket* createPacket(const util::Name &name, util::BinaryBuffer data);

        protected:
           void initProperties();
        };
    }
}
#endif // CCNXCONTENTOBJECTBUILDER_H
