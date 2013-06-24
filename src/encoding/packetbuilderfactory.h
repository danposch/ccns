#ifndef PACKETBUILDERFACTORY_H
#define PACKETBUILDERFACTORY_H

#include <cstddef>

#include "ipacketbuilder.h"
#include "ccnxinterstbuilder.h"
#include "ccnxcontentobjectbuilder.h"

class PacketBuilderFactory
{
public:
    PacketBuilderFactory();

    IPacketBuilder* createPacketBuilder(IPacketBuilder::PacketBuilderType type);
};

#endif // PACKETBUILDERFACTORY_H
