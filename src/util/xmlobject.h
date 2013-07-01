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


            void createNewXmlDocument( xmlChar *rootNodeName );

            int dump(BinaryBuffer *buffer);

        private:
            xmlDocPtr doc;
        };
    }
}

#endif // XMLOBJECT_H
