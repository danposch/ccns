#ifndef CCNXCONTENTOBJECTBUILDER_H
#define CCNXCONTENTOBJECTBUILDER_H

#include "abstractpacketbuilder.h"
#include "ipacket.h"
#include "ccnxcontentobject.h"

class CCNxContentObjectBuilder : public AbstractPacketBuilder
{
public:
    CCNxContentObjectBuilder();

    IPacket* createPacket(const std::string &name, unsigned char* blob);
};

#endif // CCNXCONTENTOBJECTBUILDER_H
