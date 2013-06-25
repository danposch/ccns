#ifndef PACKETBUILDERFACTORY_H
#define PACKETBUILDERFACTORY_H

#include <cstddef>

#include "ipacketbuilder.h"
#include "ccnxinterstbuilder.h"
#include "ccnxcontentobjectbuilder.h"

namespace ccns
{
    namespace encoding
    {
        class PacketBuilderFactory
        {
            public:
                static IPacketBuilder* createPacketBuilder(IPacketBuilder::PacketBuilderType type);
        };

    }
}

#endif // PACKETBUILDERFACTORY_H
