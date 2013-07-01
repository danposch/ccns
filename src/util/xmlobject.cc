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

void XmlObject::createNewXmlDocument(xmlChar* rootNodeName)
{
    if(doc != NULL)
        xmlFreeDoc(doc);

    doc = xmlNewDoc( (const xmlChar*)"1.0" );
    xmlDocSetRootElement(doc, xmlNewNode(NULL, rootNodeName));
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



