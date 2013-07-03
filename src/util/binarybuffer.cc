#include "binarybuffer.h"

using namespace ccns::util;

BinaryBuffer::BinaryBuffer()
{
    buffer = NULL;
    curLength = 0;
    maxLength = 0;
}

BinaryBuffer::BinaryBuffer(const unsigned char *data, size_t length)
{
    init(data,length);
}

void BinaryBuffer::init(const unsigned char *data, size_t length)
{
    buffer = (unsigned char*)malloc(length);
    memcpy(buffer, data, length);

    curLength = length;
    maxLength = length;
}

BinaryBuffer::~BinaryBuffer()
{
    if(buffer != NULL)
        free(buffer);
}

BinaryBuffer& BinaryBuffer::append(const unsigned char *data, size_t length)
{
    if(buffer == NULL)
    {
        init(data,length);
        return *this;
    }

    if(curLength+length <= maxLength)
        memcpy(buffer+curLength, data, length);
    else
    {
        resize(curLength+length);
        memcpy(buffer+curLength, data, length);
    }

    curLength += length;

    return *this;
}

BinaryBuffer& BinaryBuffer::append(BinaryBuffer other)
{
    this->append(other.data(), other.length());
    return *this;
}

BinaryBuffer& BinaryBuffer::clear()
{
    curLength = 0;
    return *this;
}

void BinaryBuffer::resize(size_t length)
{
    // we always double the buffer at least

    if(maxLength <= 0)
        maxLength = 1;

    while(maxLength < length)
        maxLength *= 2;

    buffer = (unsigned char*) realloc((void*)buffer, maxLength);
}

void BinaryBuffer::shrink(size_t length)
{
    // we only shrink if we can take away at least a thrid of the size

    while((maxLength-(maxLength/3)) > length)
        maxLength -= maxLength/3;

    buffer = (unsigned char*) realloc((void*)buffer, maxLength);
}

BinaryBuffer& BinaryBuffer::operator=(BinaryBuffer const& other)
{
    this->maxLength = other.maxLength;
    this->curLength = other.curLength;

    this->buffer = (unsigned char*) realloc((void*)this->buffer, maxLength);

    memcpy(this->buffer, other.buffer, curLength);

    return *this;
}

BinaryBuffer::BinaryBuffer(const BinaryBuffer& other)
{
    buffer = NULL;
    *this = other;
}

BinaryBuffer BinaryBuffer::operator+(BinaryBuffer const& other)
{
    BinaryBuffer b;
    b.append(this->buffer, this->curLength);
    b.append(other.buffer, other.curLength);
    return b;
}

BinaryBuffer& BinaryBuffer::toBase64()
{
    CryptoPP::Base64Encoder b64encoder(NULL,false);
    encode(*this, b64encoder);

    return *this;
}

BinaryBuffer& BinaryBuffer::fromBase64()
{
    CryptoPP::Base64Decoder b64decoder(NULL);
    encode(*this, b64decoder);

    return *this;
}

BinaryBuffer& BinaryBuffer::toHex()
{
    CryptoPP::HexEncoder hexEncoder;
    encode(*this, hexEncoder);

    return *this;
}

BinaryBuffer& BinaryBuffer::fromHex()
{
    CryptoPP::HexDecoder hexDecoder;
    encode(*this, hexDecoder);

    return *this;
}

BinaryBuffer BinaryBuffer::getBase64Copy()
{
    BinaryBuffer copy = *this;
    copy.toBase64();

    return copy;
}

BinaryBuffer BinaryBuffer::getHexCopy()
{
    BinaryBuffer copy = *this;
    copy.toHex();

    return copy;
}

BinaryBuffer& BinaryBuffer::encode(BinaryBuffer &buf, CryptoPP::Filter &filter)
{
    filter.Put(buf.buffer, buf.curLength);
    filter.MessageEnd();

    size_t count = filter.MaxRetrievable();


    if(count > buf.curLength)
        buf.resize(count);
    else
        buf.shrink(count);

    buf.curLength = filter.Get(buf.buffer, count);

    return buf;
}

std::string BinaryBuffer::getString()
{
    return std::string((const char*)buffer, curLength);
}
