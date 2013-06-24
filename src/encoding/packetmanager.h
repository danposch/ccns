#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H

#include <cstddef>
#include <boost/unordered_map.hpp>

#include "packetbuilderfactory.h"
#include "ipacketbuilder.h"
#include "ipacket.h"

class PacketManager
{

public:
    PacketManager();
    ~PacketManager();

    IPacket* createInterest(std::string name);
    IPacket* createContentObject(std::string name, unsigned char *blob);

private:

    PacketBuilderFactory *factory;

    IPacketBuilder* getPacketBuilder(IPacketBuilder::PacketBuilderType type);

    typedef boost::unordered_map<IPacketBuilder::PacketBuilderType,  IPacketBuilder*> BuilderMap;
    BuilderMap bmap;

};

#endif // PACKETMANAGER_H
