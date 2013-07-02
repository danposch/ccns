#include "ccnxinterest.h"

#include <iostream>
#include <fstream>

using namespace ccns::encoding;

CCNxInterest::CCNxInterest(const util::Name &name, PropertyMap props) : AbstractPacket(IPacket::CCNxInterest, name, props)
{
    this->props = props;
}

ccns::util::BinaryBuffer CCNxInterest::xmlSerialize()
{
    ccns::util::XmlObject xml;

    // add rootNode
    xmlNodePtr root = xml.createNewXmlDocument((xmlChar*) ("Interest"));

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

    // Check for optional properties

    //add MinSuffixComponents
    PropertyMap::iterator it = props.find(MIN_SUFFIX_COMPONENTS);
    if(it != props.end())
        addSimpleUIntNode(&xml, root, MIN_SUFFIX_COMPONENTS);

    //add MaxSuffixComponents
    it = props.find(MAX_SUFFIX_COMPONENTS);
    if(it != props.end())
        addSimpleUIntNode(&xml, root, MAX_SUFFIX_COMPONENTS);

    //TODO EXCLUDE

    //ChildSelector
    it = props.find(CHILD_SELECTOR);
    if(it != props.end())
        addSimpleUIntNode(&xml, root, CHILD_SELECTOR);

    //add AnswerOriginKind
    it = props.find(ANSWER_ORIGIN_KIND);
    if(it != props.end())
        addSimpleUIntNode(&xml, root, ANSWER_ORIGIN_KIND);

    //Scope
    it = props.find(SCOPE);
    if(it != props.end())
        addSimpleUIntNode(&xml, root, SCOPE);

    //TODO INTERESTLIFETIME

    // TODO append a random nonce....

    util::BinaryBuffer buf;
    xml.dump(&buf);

    return buf;
}

void CCNxInterest::addSimpleUIntNode(util::XmlObject *obj, xmlNodePtr parent, const char* nodeName)
{
    PropertyMap::iterator it = props.find(nodeName);
    std::string value = boost::lexical_cast<std::string>(boost::any_cast<unsigned int>(it->second));
    obj->addNode(parent, (xmlChar*) nodeName , (xmlChar*) value.c_str());
}
