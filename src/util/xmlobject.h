#ifndef XMLOBJECT_H
#define XMLOBJECT_H

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "binarybuffer.h"

namespace ccns
{
    namespace util
    {
        class XmlObject
        {
        public:
            XmlObject();
            virtual ~XmlObject();

            xmlNodePtr createNewXmlDocument( xmlChar *rootNodeName );
            xmlNodePtr addNode(xmlNodePtr parent, xmlChar* nodeName, xmlChar* content = NULL);
            bool addAttribute(xmlNodePtr node, xmlChar* attributeName, xmlChar* attributeValue);

            int dump(BinaryBuffer *buffer);

        private:
            xmlDocPtr doc;
        };
    }
}

#endif // XMLOBJECT_H
