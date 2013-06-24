#ifndef IPACKET_H
#define IPACKET_H

#include <string>

class IPacket
{
public:

    virtual int getType() = 0;

    virtual std::string getName() = 0;

    virtual int prefixMatch(const std::string &name) = 0;
};

#endif // IPACKET_H
