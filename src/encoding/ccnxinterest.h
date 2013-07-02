#ifndef CCNXINTEREST_H
#define CCNXINTEREST_H

#define MIN_SUFFIX_COMPONENTS "MinSuffixComponents"
#define MAX_SUFFIX_COMPONENTS "MaxSuffixComponents"
#define CHILD_SELECTOR "ChildSelector"
#define ANSWER_ORIGIN_KIND "AnswerOriginKind"
#define SCOPE "Scope"


#include <boost/lexical_cast.hpp>

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
            void addSimpleUIntNode(util::XmlObject *obj, xmlNodePtr parent, char* nodeName);
        };
    }
}

#endif // CCNXINTEREST_H
