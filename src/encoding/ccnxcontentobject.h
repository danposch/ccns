#ifndef CCNXCONTENTOBJECT_H
#define CCNXCONTENTOBJECT_H

#include "abstractpacket.h"

namespace ccns
{
    namespace encoding
    {
        class CCNxContentObject : public AbstractPacket
        {
        public:
            CCNxContentObject(const std::string &name, unsigned char* blob);
        };
    }
}
#endif // CCNXCONTENTOBJECT_H
