#ifndef BINARYBUFFER_H
#define BINARYBUFFER_H

#include <cstddef>
#include <stdlib.h>
#include <string.h>

namespace ccns
{
    namespace util
    {

        class BinaryBuffer
        {
        public:
            BinaryBuffer();
            BinaryBuffer(unsigned char* data, size_t length);

            ~BinaryBuffer();

            BinaryBuffer* append(unsigned char* data, size_t length);

            BinaryBuffer& operator=(BinaryBuffer const& other);
            BinaryBuffer operator+(BinaryBuffer const& other);
            //const BinaryBuffer operator+(BinaryBuffer const& left, BinaryBuffer const& right);

        private:

            void resize(size_t new_min_length);

            unsigned char *buffer;
            size_t curLength;
            size_t maxLength;
        };
    }
}
#endif // BINARYBUFFER_H
