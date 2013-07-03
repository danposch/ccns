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

            AbstractPacketBuilder();

            virtual IPacket* createPacket(const util::Name &name, const util::BinaryBuffer &data);
            virtual IPacket* createPacket(const util::Name &name);

            void setDefaultSettings(PropertyMap props);

            virtual void addSetting(std::string settingName, boost::any value);
            virtual void removeSetting(std::string settingName);

        protected:

            virtual void initProperties() = 0;
            PropertyMap props;

        };
    }
}

#endif // ABSTRACTPACKETBUILDER_H
