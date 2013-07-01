#ifndef CCNXINTEREST_H
#define CCNXINTEREST_H

#include <boost/date_time/posix_time/posix_time.hpp>

#include "abstractpacket.h"
#include "binarybuffer.h"
#include "xmlobject.h"

// see http://www.ccnx.org/releases/latest/doc/technical/InterestMessage.html

namespace ccns
{
    namespace encoding
    {

        class CCNxInterest : public AbstractPacket
        {

        public:
            CCNxInterest(std::string name);

            util::BinaryBuffer serialize();

        private:

            static xmlChar* rootName;

            unsigned int minSuffixComponents;
            unsigned int maxSuffixComponents;
            std::string publisherDigest;
            std::string exclude;
            unsigned int childselector;
            unsigned int answerOriginKind;
            unsigned int scope;
            boost::posix_time::ptime interestLifetime;
            std::string nonce;
            unsigned int faceId;

        };
    }
}

#endif // CCNXINTEREST_H
