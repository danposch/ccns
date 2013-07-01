#include "abstractpacketbuilder.h"

using namespace ccns::encoding;

AbstractPacketBuilder::AbstractPacketBuilder()
{
}

void AbstractPacketBuilder::setDefaultSettings()
{

}

IPacket* AbstractPacketBuilder::createPacket(const util::Name &, util::BinaryBuffer data )
{
    return NULL;
}

IPacket* AbstractPacketBuilder::createPacket(const util::Name &)
{
    return NULL;
}
