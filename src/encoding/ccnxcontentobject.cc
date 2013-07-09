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

    // add Signature
    xmlNodePtr sigRoot = xml.addNode(root, (xmlChar*) "Signature");

    //crypto::IDigitalSignature *algo = crypto::DigitalSignatureFactory::getSignatureAlgorithm(crypto::IDigitalSignature::DSA);

    //todo add correct signature --> careful u need to sign a lot of data..
    xmlNodePtr bitsNode = xml.addNode(sigRoot, (xmlChar*) "SignatureBits", (xmlChar*)"FAKE SIGNATURE");
    xml.addAttribute(bitsNode, (xmlChar*) "ccnbencoding", (xmlChar*) "base64Binary");

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

    //add signed info

    xmlNodePtr infoRoot = xml.addNode(root, (xmlChar*) "SignedInfo");

    //add content
    util::BinaryBuffer c = content.getBase64Copy();
    cur = xml.addNode(root, (xmlChar*)"Content",xmlCharStrndup((char*)c.data(),c.length()));
    xml.addAttribute(cur, (xmlChar*) "ccnbencoding", (xmlChar*) "base64Binary");

    util::BinaryBuffer buf;
    xml.dump(&buf);

    //delete(algo);
    return buf;
}
