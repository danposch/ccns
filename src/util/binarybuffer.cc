#include "binarybuffer.h"

using namespace ccns::util;

BinaryBuffer::BinaryBuffer()
{
    buffer = NULL;
    curLength = 0;
    maxLength = 0;
}

BinaryBuffer::BinaryBuffer(unsigned char *data, size_t length)
{
    init(data,length);
}

void BinaryBuffer::init(unsigned char *data, size_t length)
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

BinaryBuffer& BinaryBuffer::append(unsigned char *data, size_t length)
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

void BinaryBuffer::resize(size_t length)
{
    // we always double the buffer at least

    if(maxLength <= 0)
        maxLength = 1;

    while(maxLength < length)
        maxLength *= 2;

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

BinaryBuffer& BinaryBuffer::operator+(BinaryBuffer const& other)
{

    this->append(other.buffer, other.curLength);

    return *this;
}
