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

            AbstractPacket(int type, const util::Name &name, PropertyMap props);

            int getType();

            util::Name getName();

            int prefixMatch(const std::string &name);

            virtual ccns::util::BinaryBuffer xmlSerialize();

        protected:

            int packetType;
            util::Name packetName;

            PropertyMap props;

        };
    }
}

#endif // ABSTRACTPACKET_H
