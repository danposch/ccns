#ifndef CCNXCONTENTOBJECT_H
#define CCNXCONTENTOBJECT_H

#include <boost/lexical_cast.hpp>

#include "abstractpacket.h"
#include "binarybuffer.h"
#include "name.h"
#include "xmlobject.h"

namespace ccns
{
    namespace encoding
    {
        class CCNxContentObject : public AbstractPacket
        {
        public:
            CCNxContentObject(const util::Name &name, const util::BinaryBuffer &data, PropertyMap props = PropertyMap());

            util::BinaryBuffer xmlSerialize();

        private:
            util::BinaryBuffer content;
        };
    }
}
#endif // CCNXCONTENTOBJECT_H
