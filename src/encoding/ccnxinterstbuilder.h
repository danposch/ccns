#ifndef CCNXINTERSTBUILDER_H
#define CCNXINTERSTBUILDER_H

#include <iostream>

#include "abstractpacketbuilder.h"
#include "ipacket.h"
#include "ccnxinterest.h"

class CCNxInterstBuilder : public AbstractPacketBuilder
{
public:
    CCNxInterstBuilder();

    IPacket* createPacket(const std::string &name, unsigned char*);
};

#endif // CCNXINTERSTBUILDER_H
