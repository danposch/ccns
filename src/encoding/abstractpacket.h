#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H

#include "ipacket.h"

class AbstractPacket : public IPacket
{
public:
    AbstractPacket();

    int getType();

    std::string getName();

    int prefixMatch(const std::string &name);

protected:

    int packetType;
    std::string packetName;

};

#endif // ABSTRACTPACKET_H
