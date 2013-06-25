#include "abstractpacketbuilder.h"

using namespace ccns::encoding;

AbstractPacketBuilder::AbstractPacketBuilder()
{
}

void AbstractPacketBuilder::setDefaultSettings()
{

}

IPacket* AbstractPacketBuilder::createPacket(const std::string &, unsigned char* )
{
    return NULL;
}

IPacket* AbstractPacketBuilder::createPacket(const std::string &)
{
    return NULL;
}
