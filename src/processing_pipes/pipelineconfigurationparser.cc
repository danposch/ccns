#include "pipelineconfigurationparser.h"

using namespace ccns::processing;

PipelineConfigurationParser* PipelineConfigurationParser::parser = NULL;

PipelineConfigurationParser* PipelineConfigurationParser::Instance()
{
    if(parser == NULL)
    {
        LIBXML_TEST_VERSION
        xmlInitParser();
        parser = new PipelineConfigurationParser;
    }
    return parser;
}

boost::container::list<std::string> PipelineConfigurationParser::getFilters(const std::string &pipelineName, const std::string &file)
{
    boost::container::list<std::string> res;
    xmlDoc *doc = xmlReadFile(file.c_str(), NULL, 0);
    if(doc == NULL)
        return res;

    xmlXPathContextPtr context = xmlXPathNewContext(doc);

    std::string query = "/Configuration/Pipelines/Pipeline[@name='";
                query.append(pipelineName);
                query.append("']/filters/filter/text()");

    xmlXPathObjectPtr result = xmlXPathEvalExpression((xmlChar*)query.c_str(), context);
    if(context != NULL)
        xmlXPathFreeContext(context);

    if(result != NULL)
    {
        xmlNodeSetPtr nodes = result->nodesetval;
        for(int i = 0; i < nodes->nodeNr; i++)
        {
            res.push_back(std::string((char*) xmlNodeListGetString(doc, nodes->nodeTab[i], 1)));
        }
        xmlXPathFreeObject(result);
    }

    if(doc != NULL)
        xmlFreeDoc(doc);
    return res;
}

PipelineConfigurationParser::PipelineConfigurationParser()
{
}
