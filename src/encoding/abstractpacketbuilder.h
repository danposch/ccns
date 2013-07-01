#ifndef ABSTRACTPACKETBUILDER_H
#define ABSTRACTPACKETBUILDER_H

#include <boost/unordered_map.hpp>
#include <boost/any.hpp>

#include "ipacketbuilder.h"
#include "ipacket.h"
#include "binarybuffer.h"
#include "name.h"

namespace ccns
{
    namespace encoding
    {
        class AbstractPacketBuilder : public IPacketBuilder
        {
        public:

            typedef boost::unordered_map<std::string, boost::any> PropertyMap;

            AbstractPacketBuilder();

            virtual IPacket* createPacket(const util::Name &name, util::BinaryBuffer data);
            virtual IPacket* createPacket(const util::Name &name);

            void setDefaultSettings();

        protected:
            PropertyMap props;

        };
    }
}

#endif // ABSTRACTPACKETBUILDER_H
