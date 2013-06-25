#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H

#include <cstddef>
#include <boost/unordered_map.hpp>

#include "packetbuilderfactory.h"
#include "ipacketbuilder.h"
#include "ipacket.h"

namespace ccns
{
    namespace encoding
    {
        class PacketManager
        {

        public:
            PacketManager();
            virtual ~PacketManager();

            IPacketBuilder* getPacketBuilder(IPacketBuilder::PacketBuilderType type);

            //IPacket* createInterest(std::string name);
            //IPacket* createContentObject(std::string name, unsigned char *blob);

        private:
            typedef boost::unordered_map<IPacketBuilder::PacketBuilderType,  IPacketBuilder*> BuilderMap;
            BuilderMap bmap;

        };
    }
}
#endif // PACKETMANAGER_H
