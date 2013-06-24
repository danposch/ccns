#include "ccnxinterstbuilder.h"

CCNxInterstBuilder::CCNxInterstBuilder()
{

}

IPacket* CCNxInterstBuilder::createPacket(const std::string &name, unsigned char*)
{
    return new CCNxInterest(name);
}
