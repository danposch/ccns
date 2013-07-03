#include "ccnxinterstbuilder.h"

using namespace ccns::encoding;

CCNxInterstBuilder::CCNxInterstBuilder()
{
    initProperties();
}

void CCNxInterstBuilder::initProperties()
{
    props.clear();

    props[MIN_SUFFIX_COMPONENTS] = (unsigned int) 0;
    props[MAX_SUFFIX_COMPONENTS] = (unsigned int) UINT_MAX;
    props[CHILD_SELECTOR] = (unsigned int) 1;
    props[ANSWER_ORIGIN_KIND] = (unsigned int) 3;
    props[SCOPE] = (unsigned int) 2;
}

IPacket* CCNxInterstBuilder::createPacket(const util::Name &name, const util::BinaryBuffer&)
{
    return createPacket(name);
}

IPacket* CCNxInterstBuilder::createPacket(const util::Name &name)
{
    return new CCNxInterest(name, props);
}
