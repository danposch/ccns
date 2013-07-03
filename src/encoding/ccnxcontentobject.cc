#include "ccnxcontentobject.h"

using namespace ccns::encoding;

CCNxContentObject::CCNxContentObject(const util::Name &name, const util::BinaryBuffer &data, PropertyMap props) : AbstractPacket(IPacket::CCNxContentObject, name, props)
{
    this->content = data;
}

ccns::util::BinaryBuffer CCNxContentObject::xmlSerialize()
{
    ccns::util::XmlObject xml;

    // add rootNode
    xmlNodePtr root = xml.createNewXmlDocument((xmlChar*) ("ContentObject"));

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

    //todo

    util::BinaryBuffer buf;
    xml.dump(&buf);

    return buf;
}
