#ifndef ABSTRACTPACKETBUILDER_H
#define ABSTRACTPACKETBUILDER_H

#include "ipacketbuilder.h"
#include "ipacket.h"

class AbstractPacketBuilder : public IPacketBuilder
{
public:
    AbstractPacketBuilder();

    virtual IPacket* createPacket(const std::string &name, unsigned char* blob) = 0;

    void setDefaultSettings();
};

#endif // ABSTRACTPACKETBUILDER_H
