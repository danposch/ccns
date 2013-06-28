#include "ccnxcontentobject.h"

using namespace ccns::encoding;

CCNxContentObject::CCNxContentObject(const std::string &name, util::BinaryBuffer data) : AbstractPacket(IPacket::CCNxContentObject, name)
{

}
