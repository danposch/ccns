#include "ccnxcontentobjectbuilder.h"

CCNxContentObjectBuilder::CCNxContentObjectBuilder()
{
}


IPacket* CCNxContentObjectBuilder::createPacket(const std::string &name, unsigned char* blob)
{
    return new CCNxContentObject(name, blob);
}
