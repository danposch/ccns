#include "ccnxinterstbuilder.h"

using namespace ccns::encoding;

CCNxInterstBuilder::CCNxInterstBuilder()
{
    //create a property map
}

IPacket* CCNxInterstBuilder::createPacket(const util::Name &name, util::BinaryBuffer)
{
    return createPacket(name);
}

IPacket* CCNxInterstBuilder::createPacket(const util::Name &name)
{
    return new CCNxInterest(name);
}
