#ifndef CCNXCONTENTOBJECT_H
#define CCNXCONTENTOBJECT_H

#include "abstractpacket.h"
#include "binarybuffer.h"
#include "name.h"

namespace ccns
{
    namespace encoding
    {
        class CCNxContentObject : public AbstractPacket
        {
        public:
            CCNxContentObject(const util::Name &name, util::BinaryBuffer data, PropertyMap props = PropertyMap());
        };
    }
}
#endif // CCNXCONTENTOBJECT_H
