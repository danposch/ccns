#include "packetbuilderfactory.h"

using namespace ccns::encoding;

IPacketBuilder* PacketBuilderFactory::createPacketBuilder(IPacketBuilder::PacketBuilderType type)
{
    if(type == IPacketBuilder::InterestBuilder)
        return new CCNxInterstBuilder();

    if(type == IPacketBuilder::ContentObjectBuilder)
        return new CCNxContentObjectBuilder();

    return NULL;
}
