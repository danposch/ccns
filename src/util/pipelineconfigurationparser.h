#ifndef PIPELINECONFIGURATIONPARSER_H
#define PIPELINECONFIGURATIONPARSER_H

#include "libxml/tree.h"
#include "libxml/parser.h"
#include "libxml/xpath.h"

#include <boost/container/list.hpp>

#include <string.h>

namespace ccns
{
    namespace util
    {
        class PipelineConfigurationParser
        {
        public:
            static PipelineConfigurationParser* Instance();
            boost::container::list<std::string> getFilters(const std::string &pipelineName, const std::string &file);

        protected:
            static PipelineConfigurationParser *parser;
            PipelineConfigurationParser();

        };
    }
}

#endif // PIPELINECONFIGURATIONPARSER_H
