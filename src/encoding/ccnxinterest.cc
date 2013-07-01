#include "ccnxinterest.h"

#include <iostream>
#include <fstream>

using namespace ccns::encoding;

xmlChar* CCNxInterest::rootName = (xmlChar*) ("Interest");

CCNxInterest::CCNxInterest(const util::Name &name, PropertyMap props) : AbstractPacket(IPacket::CCNxInterest, name, props)
{
   /*minSuffixComponents = 0;
   maxSuffixComponents = UINT_MAX;
   childselector = 1;
   answerOriginKind = 3;*/
}

ccns::util::BinaryBuffer CCNxInterest::xmlSerialize()
{
    ccns::util::XmlObject xml;

    // add rootNode
    xmlNodePtr root = xml.createNewXmlDocument(rootName);

    //add Name
    std::vector<util::BinaryBuffer> comp = this->packetName.getComponents();

    xmlNodePtr nameRoot = xml.addNode(root, (xmlChar*)"Name");
    xmlNodePtr cur = NULL;

    util::BinaryBuffer tmp;
    for(std::vector<util::BinaryBuffer>::iterator it = comp.begin(); it != comp.end(); ++it)
    {
        tmp = (*it).getBase64Copy();
        cur = xml.addNode(nameRoot, (xmlChar*)"Component",xmlCharStrndup((char*)tmp.data(),tmp.length()));
        xml.addAttribute(cur, (xmlChar*) "ccnbencoding", (xmlChar*) "base64Binary");
    }

    util::BinaryBuffer buf;
    xml.dump(&buf);

    return buf;
}
