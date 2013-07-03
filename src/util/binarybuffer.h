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

        class BinaryBuffer
        {
        public:
            BinaryBuffer();
            BinaryBuffer(const unsigned char* data, size_t length);

            virtual ~BinaryBuffer();

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

            BinaryBuffer getHexCopy();
            BinaryBuffer getBase64Copy();
            std::string  getString();

            size_t length(){return curLength;}
            unsigned char* data(){return buffer;}

        private:

            BinaryBuffer& encode(BinaryBuffer &buf, CryptoPP::Filter &filter);

            void resize(size_t new_min_length);
            void shrink(size_t new_min_length);

            void init(const unsigned char *data, size_t length);

            unsigned char *buffer;
            size_t curLength;
            size_t maxLength;
        };
    }
}
#endif // BINARYBUFFER_H
