#ifndef ABSTRACTPACKETBUILDER_H
#define ABSTRACTPACKETBUILDER_H

#include "ipacketbuilder.h"

class AbstractPacketBuilder : public IPacketBuilder
{
public:
    AbstractPacketBuilder();

    void setDefaultSettings();
};

#endif // ABSTRACTPACKETBUILDER_H
