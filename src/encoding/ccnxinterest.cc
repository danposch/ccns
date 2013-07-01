#include "ccnxinterest.h"

#include <iostream>
#include <fstream>

using namespace ccns::encoding;

xmlChar* CCNxInterest::rootName = (xmlChar*) ("Interest");

CCNxInterest::CCNxInterest(const util::Name &name) : AbstractPacket(IPacket::CCNxInterest, name)
{
   minSuffixComponents = 0;
   maxSuffixComponents = UINT_MAX;
   childselector = 1;
   answerOriginKind = 3;
}

ccns::util::BinaryBuffer CCNxInterest::serialize()
{
    ccns::util::XmlObject xml;

    xml.createNewXmlDocument(rootName);

    ccns::util::BinaryBuffer buf;

    xml.dump(&buf);

    return buf;
}
