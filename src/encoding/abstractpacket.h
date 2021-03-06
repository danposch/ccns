#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H

#include <boost/unordered_map.hpp>
#include <boost/any.hpp>

#include "ipacket.h"
#include "binarybuffer.h"
#include "name.h"

namespace ccns
{
    namespace encoding
    {
        class AbstractPacket : public IPacket
        {

        public:
            typedef boost::unordered_map<std::string, boost::any> PropertyMap;

            AbstractPacket(IPacketType type, const util::Name &name, PropertyMap props);

            IPacketType getType();

            util::Name getName();

            int prefixMatch(const std::string &name);

            virtual ccns::util::BinaryBuffer xmlSerialize() = 0;

        protected:

            IPacketType packetType;
            util::Name packetName;

            PropertyMap props;

        };
    }
}

#endif // ABSTRACTPACKET_H
