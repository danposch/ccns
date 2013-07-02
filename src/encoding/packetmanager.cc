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
    BuilderMap::iterator it = bmap.find(type);

    if(it == bmap.end())
    {
        bmap.insert(BuilderMap::value_type(type, PacketBuilderFactory::createPacketBuilder(type)));
        return bmap.find(type)->second;
    }

    return it->second;
}
