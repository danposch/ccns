#ifndef CCNXCONTENTOBJECT_H
#define CCNXCONTENTOBJECT_H

#include "abstractpacket.h"
#include "binarybuffer.h"

namespace ccns
{
    namespace encoding
    {
        class CCNxContentObject : public AbstractPacket
        {
        public:
            CCNxContentObject(const std::string &name, util::BinaryBuffer data);
        };
    }
}
#endif // CCNXCONTENTOBJECT_H
