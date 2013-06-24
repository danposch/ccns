#include "packetbuilderfactory.h"

PacketBuilderFactory::PacketBuilderFactory()
{
}


IPacketBuilder* PacketBuilderFactory::createPacketBuilder(IPacketBuilder::PacketBuilderType type)
{
    if(type == IPacketBuilder::InterestBuilder)
        return new CCNxInterstBuilder();

    if(type == IPacketBuilder::ContentObjectBuilder)
        return new CCNxContentObjectBuilder();

    return NULL;
}
