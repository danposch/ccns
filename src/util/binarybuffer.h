#ifndef BINARYBUFFER_H
#define BINARYBUFFER_H

#include <cstddef>
#include <stdlib.h>
#include <string.h>

#include <cryptopp/base64.h>

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
            BinaryBuffer(unsigned char* data, size_t length);

            virtual ~BinaryBuffer();

            BinaryBuffer& append(unsigned char* data, size_t length);

            BinaryBuffer(const BinaryBuffer& other);
            BinaryBuffer& operator=(BinaryBuffer const& other);
            BinaryBuffer operator+(BinaryBuffer const& other);

            BinaryBuffer& toBase64();
            BinaryBuffer& toBinary();

            size_t length(){return curLength;}
            unsigned char* data(){return buffer;}

        private:

            void resize(size_t new_min_length);
            void shrink(size_t new_min_length);

            void init(unsigned char* data, size_t length);

            unsigned char *buffer;
            size_t curLength;
            size_t maxLength;
        };
    }
}
#endif // BINARYBUFFER_H
