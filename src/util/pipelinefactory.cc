#include "pipelinefactory.h"

using namespace ccns::util;

template <class T>

ccns::util::PipelineManager<T> * PipelineFactory::CreateFromConfig(const std::string &pipelineName, const std::string &file)
{
    FilterChain<T> *chain = new FilterChain<T>();

    //TODO create the filters and push them into the chain.

    return new ccns::util::PipelineManager<T>(chain);
}
