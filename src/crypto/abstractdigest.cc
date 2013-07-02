#include "abstractdigest.h"

using namespace ccns::crypto;

AbstractDigest::AbstractDigest(IDigestType type)
{
    digestType = type;
}

IDigest::IDigestType AbstractDigest::getType()
{
    return digestType;
}


void AbstractDigest::reset()
{
    this->buf.clear();
}

void AbstractDigest::add(const util::BinaryBuffer &buffer)
{
    this->buf.append(buffer);
}

void AbstractDigest::add(unsigned char *data, size_t length)
{
    this->buf.append(data, length);
}
