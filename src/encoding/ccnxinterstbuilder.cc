#include "ccnxinterstbuilder.h"

using namespace ccns::encoding;

CCNxInterstBuilder::CCNxInterstBuilder()
{

}

IPacket* CCNxInterstBuilder::createPacket(const std::string &name, util::BinaryBuffer)
{
    return createPacket(name);
}

IPacket* CCNxInterstBuilder::createPacket(const std::string &name)
{
    return new CCNxInterest(name);
}
