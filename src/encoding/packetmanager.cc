#include "packetmanager.h"

using namespace ccns::encoding;

PacketManager::PacketManager()
{
}

PacketManager::~PacketManager()
{
}

IPacketBuilder* PacketManager::getPacketBuilder(IPacketBuilder::PacketBuilderType type)
{
    if( bmap.find(type) == bmap.end())
    {
        bmap.insert(BuilderMap::value_type(type, PacketBuilderFactory::createPacketBuilder(type)));
    }

    return bmap.find(type)->second;
}
