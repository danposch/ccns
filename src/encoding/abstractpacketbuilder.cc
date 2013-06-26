#include "abstractpacketbuilder.h"

using namespace ccns::encoding;

AbstractPacketBuilder::AbstractPacketBuilder()
{
}

void AbstractPacketBuilder::setDefaultSettings()
{

}

IPacket* AbstractPacketBuilder::createPacket(const std::string &, util::BinaryBuffer data )
{
    return NULL;
}

IPacket* AbstractPacketBuilder::createPacket(const std::string &)
{
    return NULL;
}
