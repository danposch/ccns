#include "ccnxcontentobjectbuilder.h"

using namespace ccns::encoding;

CCNxContentObjectBuilder::CCNxContentObjectBuilder()
{
}


IPacket* CCNxContentObjectBuilder::createPacket(const util::Name &name, const util::BinaryBuffer &data)
{
    return new CCNxContentObject(name, data);
}

void CCNxContentObjectBuilder::initProperties()
{
    props.clear();

    //todo check if we need properties
}
