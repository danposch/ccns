#ifndef CCNXINTEREST_H
#define CCNXINTEREST_H

#include "abstractpacket.h"
#include "binarybuffer.h"
#include "name.h"
#include "xmlobject.h"

// see http://www.ccnx.org/releases/latest/doc/technical/InterestMessage.html

namespace ccns
{
    namespace encoding
    {

        class CCNxInterest : public AbstractPacket
        {

        public:
            CCNxInterest(const util::Name &name, PropertyMap props = PropertyMap());

            util::BinaryBuffer xmlSerialize();

        private:

            static xmlChar* rootName;

            /*unsigned int minSuffixComponents;
            unsigned int maxSuffixComponents;
            std::string publisherDigest;
            std::string exclude;
            unsigned int childselector;
            unsigned int answerOriginKind;
            unsigned int scope;
            boost::posix_time::ptime interestLifetime;
            std::string nonce;
            unsigned int faceId;*/

        };
    }
}

#endif // CCNXINTEREST_H
