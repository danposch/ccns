#ifndef IPACKET_H
#define IPACKET_H

#include <string>

#include "binarybuffer.h"

namespace ccns
{
    namespace encoding
            {
        class IPacket
        {
        public:
            enum IPacketType{CCNxInterest = 26, CCNxContentObject = 64};

            virtual ~IPacket(){}

            virtual int getType() = 0;

            virtual std::string getName() = 0;

            virtual int prefixMatch(const std::string &name) = 0;

            virtual ccns::util::BinaryBuffer serialize() = 0;
        };
    }
}
#endif // IPACKET_H
