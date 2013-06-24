#include "packetmanager.h"

PacketManager::PacketManager()
{
    this->factory = new PacketBuilderFactory();
}

PacketManager::~PacketManager()
{
    if(this->factory != NULL)
        delete factory;
}

IPacketBuilder* PacketManager::getPacketBuilder(IPacketBuilder::PacketBuilderType type)
{
    if( bmap.find(type) == bmap.end())
    {
        bmap.insert(BuilderMap::value_type(type, this->factory->createPacketBuilder(type)));
    }

    return bmap.find(type)->second;

}


IPacket* PacketManager::createInterest(std::string name)
{
    return getPacketBuilder(IPacketBuilder::InterestBuilder)->createPacket(name, NULL);
}

IPacket* PacketManager::createContentObject(std::string name, unsigned char *blob)
{
    return getPacketBuilder(IPacketBuilder::ContentObjectBuilder)->createPacket(name, blob);
}
