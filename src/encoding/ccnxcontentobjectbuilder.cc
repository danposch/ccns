#include "ccnxcontentobjectbuilder.h"

using namespace ccns::encoding;

CCNxContentObjectBuilder::CCNxContentObjectBuilder()
{
}


IPacket* CCNxContentObjectBuilder::createPacket(const util::Name &name, util::BinaryBuffer data)
{
    return new CCNxContentObject(name, data);
}
