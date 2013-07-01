#include "xmlobject.h"

using namespace ccns::util;

XmlObject::XmlObject()
{
   LIBXML_TEST_VERSION;

   doc = NULL;
}

XmlObject::~XmlObject()
{
    if(doc != NULL)
        xmlFreeDoc(doc);
}

xmlNodePtr XmlObject::createNewXmlDocument(xmlChar* rootNodeName)
{
    if(doc != NULL)
        xmlFreeDoc(doc);


    doc = xmlNewDoc( (const xmlChar*)"1.0" );
    xmlNodePtr root = xmlNewNode(NULL, rootNodeName);

    xmlDocSetRootElement(doc, root);
    return root;
}

xmlNodePtr XmlObject::addNode(xmlNodePtr parent, xmlChar* nodeName, xmlChar* content)
{
    if(parent == NULL)
        return NULL;

    return xmlNewChild(parent,NULL,nodeName, content);
}


bool XmlObject::addAttribute(xmlNodePtr node, xmlChar* attributeName, xmlChar* attributeValue)
{
    if(node == NULL)
        return false;

    xmlNewProp(node, attributeName, attributeValue);

    return true;
}

int XmlObject::dump(BinaryBuffer* buffer)
{
    xmlChar *out;
    int size = 0;

    xmlDocDumpFormatMemoryEnc(doc, &out, &size, "UTF-8", 1);
    buffer->append(out, (size_t)size);

    xmlFree(out);

    return size;
}



