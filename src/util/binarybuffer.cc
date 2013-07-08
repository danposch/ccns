#include "binarybuffer.h"

using namespace ccns::util;

BinaryBuffer::BinaryBuffer()
{
    buffer = NULL;
    curLength = 0;
    maxLength = 0;
}
/*!
  Creates a new BinaryBuffer and initializes it with data.

  @param data Pointer to the data.
  @param length Length of the data.
 */
BinaryBuffer::BinaryBuffer(const unsigned char *data, size_t length)
{
    init(data,length);
}

/*!
  Creates a new BinaryBuffer and initializes it with the data.

  @param data String that contains the data.
 */
BinaryBuffer::BinaryBuffer(const std::string& data)
{
    init((const unsigned char*)data.c_str(), data.size());
}

/*!
    The init function is responsible to allocate the required memory
    and to copy the data into its private buffer.

    @param data Pointer to the data.
    @param length Length of the data.
*/
void BinaryBuffer::init(const unsigned char *data, size_t length)
{
    buffer = (unsigned char*)malloc(length);
    memcpy(buffer, data, length);

    curLength = length;
    maxLength = length;
}

/*!
    Destroys the BinaryBuffer and frees the allocated memory.
*/
BinaryBuffer::~BinaryBuffer()
{
    if(buffer != NULL)
        free(buffer);
}

/*!
  Appends data to the BinaryBuffer.

  @param data Pointer to the data to append.
  @param length Length of the data to append.

  \returns A reference to the current buffer.
 */
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
        increase(curLength+length);
        memcpy(buffer+curLength, data, length);
    }

    curLength += length;

    return *this;
}

/*!
  Appends data to the BinaryBuffer.

  @param data String to append.

  \returns A reference to the current buffer.
 */
BinaryBuffer& BinaryBuffer::append(const std::string& data)
{
    return append((const unsigned char*)data.c_str(), data.size());
}

/*!
  Appends a BinaryBuffer to another BinaryBuffer.

  @param other The BinaryBuffer to append.

  \returns A reference to the current BinaryBuffer.
 */
BinaryBuffer& BinaryBuffer::append(BinaryBuffer other)
{
    this->append(other.data(), other.length());
    return *this;
}

/*!
    Clears the BinaryBuffer's data. Note that this function
    does not free any memory.
*/
BinaryBuffer& BinaryBuffer::clear()
{
    curLength = 0;
    return *this;
}

/*!
    Increases the internal buffer at least to the provided size.

    @param size The minimal size that should be available to
    store data.
*/
void BinaryBuffer::increase(size_t size)
{
    // we always double the buffer at least

    if(maxLength <= 0)
        maxLength = 1;

    while(maxLength < size)
        maxLength *= 2;

    buffer = (unsigned char*) realloc((void*)buffer, maxLength);
}

/*!
    Shrinks the buffer at most to the provided size.

    @param size The minimal size that should be available to
    store data.
*/
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

/*!
    Encodes this BinaryBuffer's data to BASE64.

    \returns A reference to the current BinaryBuffer.
*/
BinaryBuffer& BinaryBuffer::toBase64()
{
    CryptoPP::Base64Encoder b64encoder(NULL,false);
    encode(*this, b64encoder);

    return *this;
}

/*!
    Decodes this BinaryBuffer's data from BASE64.

    \returns A reference to the current BinaryBuffer.
*/
BinaryBuffer& BinaryBuffer::fromBase64()
{
    CryptoPP::Base64Decoder b64decoder(NULL);
    encode(*this, b64decoder);

    return *this;
}

/*!
    Encodes this BinaryBuffer's data to HEX.

    \returns A reference to the current BinaryBuffer.
*/
BinaryBuffer& BinaryBuffer::toHex()
{
    CryptoPP::HexEncoder hexEncoder;
    encode(*this, hexEncoder);

    return *this;
}

/*!
    Decodes this BinaryBuffer's data from HEX.

    \returns A reference to the current BinaryBuffer.
*/
BinaryBuffer& BinaryBuffer::fromHex()
{
    CryptoPP::HexDecoder hexDecoder;
    encode(*this, hexDecoder);

    return *this;
}

/*!
    Copys the BinaryBuffer and encodes the copy to BASE64.

    \returns The copyed BinaryBuffer.
*/
BinaryBuffer BinaryBuffer::getBase64Copy() const
{
    BinaryBuffer copy = *this;
    copy.toBase64();

    return copy;
}

/*!
    Copys the BinaryBuffer and encodes the copy to HEX.

    \returns The copyed BinaryBuffer.
*/
BinaryBuffer BinaryBuffer::getHexCopy() const
{
    BinaryBuffer copy = *this;
    copy.toHex();

    return copy;
}

/*!
    Encodes the provided BinaryBuffer with the provided filter.

    @param buf Reference to the buffer that should be encoded.
    @param filter The filter which determines the encoding type.

    \returns The encoded BinaryBuffer.
*/
BinaryBuffer& BinaryBuffer::encode(BinaryBuffer &buf, CryptoPP::Filter &filter)
{
    filter.Put(buf.buffer, buf.curLength);
    filter.MessageEnd();

    size_t count = filter.MaxRetrievable();

    if(count > buf.curLength)
        buf.increase(count);
    else
        buf.shrink(count);

    buf.curLength = filter.Get(buf.buffer, count);

    return buf;
}

/*!
    Copys the BinaryBuffer into a string. Be aware that
    std::string is '\0' terminated. Since the BinaryBuffer
    may contain '\0' this function should be only used for
    debuging and not for production code.

    \returns The copyed data as string.
*/
std::string BinaryBuffer::getString() const
{
    return std::string((const char*)buffer, curLength);
}
