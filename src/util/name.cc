#include "name.h"

using namespace ccns::util;

Name::Name(std::string name)
{
    construct(name);
}

Name::Name(char *name, size_t length)
{
    construct(std::string(name, length));
}

void Name::construct(const std::string &name)
{
    std::stringstream ss(name);
    std::string item;

    while (std::getline(ss, item, DELIMITER))
    {
        if(item.length() != 0)  //ommit leading '/' and empty components
        {
            components.push_back(BinaryBuffer((unsigned char* )item.c_str(),item.length()));
        }
    }
}

std::string Name::toString()
{
    std::string name = "/";

    if(components.size() > 0)
    {
        for(std::vector<BinaryBuffer>::iterator it = components.begin(); it != components.end(); ++it)
        {
            name.append((char*)(*it).data(), (*it).length());
            name.push_back('/');
        }
        name.erase(name.size()-1, name.size());
    }

    return name;
}
