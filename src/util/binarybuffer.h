#ifndef BINARYBUFFER_H
#define BINARYBUFFER_H

#include <cstddef>
#include <stdlib.h>
#include <string.h>

#include <cryptopp/base64.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

#include <iostream>
#include <stdio.h>

namespace ccns
{
    namespace util
    {
        /*!
          \class BinaryBuffer
          \brief The BinaryBuffer can be used to store binary data.

          The BinaryBuffer is a flexible storage that can be used to
          store any kind of data. It offers various methods to modify
          the data stored in the buffer. It is easy to append additional
          data or to convert the data into different representations.
          It supports BASE64 and HEX Encoding/Decoding.
        */
        class BinaryBuffer
        {
        public:
            BinaryBuffer();
            BinaryBuffer(const unsigned char* data, size_t length);
            BinaryBuffer(const std::string& data);

            virtual ~BinaryBuffer();

            BinaryBuffer& append(const std::string& data);
            BinaryBuffer& append(const unsigned char *data, size_t length);
            BinaryBuffer& append(BinaryBuffer other);
            BinaryBuffer& clear();

            BinaryBuffer(const BinaryBuffer& other);
            BinaryBuffer& operator=(BinaryBuffer const& other);
            BinaryBuffer operator+(BinaryBuffer const& other);

            BinaryBuffer& toBase64();
            BinaryBuffer& fromBase64();

            BinaryBuffer& toHex();
            BinaryBuffer& fromHex();

            BinaryBuffer getHexCopy() const;
            BinaryBuffer getBase64Copy() const;
            std::string  getString() const;

            size_t length() const{return curLength;}
            unsigned char* data() const{return buffer;}

        private:

            BinaryBuffer& encode(BinaryBuffer &buf, CryptoPP::Filter &filter);

            void increase(size_t size);
            void shrink(size_t new_min_length);

            void init(const unsigned char *data, size_t length);

            unsigned char *buffer;
            size_t curLength;
            size_t maxLength;
        };
    }
}
#endif // BINARYBUFFER_H
