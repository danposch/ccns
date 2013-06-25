#include "ccnxcontentobject.h"

using namespace ccns::encoding;

CCNxContentObject::CCNxContentObject(const std::string &name, unsigned char *blob) : AbstractPacket(1, name)
{

}
