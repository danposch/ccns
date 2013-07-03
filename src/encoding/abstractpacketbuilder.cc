#include "abstractpacketbuilder.h"

using namespace ccns::encoding;

AbstractPacketBuilder::AbstractPacketBuilder()
{
}

void AbstractPacketBuilder::setDefaultSettings(PropertyMap props)
{
    this->props = props;
}

void AbstractPacketBuilder::addSetting(std::string settingName, boost::any value)
{
    this->props[settingName] = value;
}

void AbstractPacketBuilder::removeSetting(std::string settingName)
{
    PropertyMap::iterator it = props.find(settingName);

    if(it != props.end())
        props.erase(it);
}

IPacket* AbstractPacketBuilder::createPacket(const util::Name &, const util::BinaryBuffer &data )
{
    return NULL;
}

IPacket* AbstractPacketBuilder::createPacket(const util::Name &)
{
    return NULL;
}
