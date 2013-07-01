#ifndef NAME_H
#define NAME_H

#include <string>
#include <boost/numeric/ublas/vector.hpp>

#include "binarybuffer.h"

#define DELIMITER '/'

namespace ccns
{
    namespace util
    {
        class Name
        {
        public:
            Name(std::string name = "");
            Name(char *name, size_t length);

            Name(const Name& other);
            Name& operator=(Name const& other);

            std::vector<BinaryBuffer> getComponents(){return components;}
            std::string toString();

        private:
            void construct(const std::string &name);
            std::vector<BinaryBuffer> components;
        };
    }
}

#endif // NAME_H
