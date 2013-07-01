#include "ccnxcontentobject.h"

using namespace ccns::encoding;

CCNxContentObject::CCNxContentObject(const util::Name &name, util::BinaryBuffer data) : AbstractPacket(IPacket::CCNxContentObject, name)
{

}
