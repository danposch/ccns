#ifndef IPACKETBUILDER_H
#define IPACKETBUILDER_H

#include <boost/unordered_map.hpp>
#include <boost/any.hpp>

#include "ipacket.h"
#include "binarybuffer.h"
#include "name.h"

namespace ccns
{
    namespace encoding
    {

        class IPacketBuilder
        {

        public:

            typedef boost::unordered_map<std::string, boost::any> PropertyMap;

            enum PacketBuilderType {InterestBuilder, ContentObjectBuilder};

            virtual void setDefaultSettings(PropertyMap props) = 0;
            virtual void addSetting(std::string settingName, boost::any value) = 0;
            virtual void removeSetting(std::string settingName) = 0;

            virtual IPacket* createPacket(const util::Name &name, util::BinaryBuffer data) = 0; // packet_data_t
            virtual IPacket* createPacket(const util::Name &name) = 0;
        };
    }
}

#endif // IPACKETBUILDER_H
