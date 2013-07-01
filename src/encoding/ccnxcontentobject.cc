#include "ccnxcontentobject.h"

using namespace ccns::encoding;

CCNxContentObject::CCNxContentObject(const util::Name &name, util::BinaryBuffer data, PropertyMap props) : AbstractPacket(IPacket::CCNxContentObject, name, props)
{

}
