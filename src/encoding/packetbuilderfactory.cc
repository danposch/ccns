#include "packetbuilderfactory.h"

PacketBuilderFactory::PacketBuilderFactory()
{
}


IPacketBuilder* PacketBuilderFactory::createPacketBuilder(IPacketBuilder::PacketBuilderType type)
{
    if(type == IPacketBuilder::ContentObjectBuilder)
        return NULL;
    if(type == IPacketBuilder::InterestBuilder)
        return new CCNxInterstBuilder();
}
