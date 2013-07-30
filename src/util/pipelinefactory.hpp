#ifndef PIPELINEFACTORY_H
#define PIPELINEFACTORY_H

#include <string.h>
#include "boost/foreach.hpp"
#include "boost/container/list.hpp"

#include "pipelinemanager.h"
#include "pipelineconfigurationparser.h"

#include "abstractfilter.hpp"

namespace ccns
{
    namespace util
    {
        template <typename T>
        class PipelineFactory
        {
        public:
            static PipelineManager<T> *CreateFromConfig(const std::string &pipelineName, const std::string &file)
            {
                FilterChain<T> *chain = new FilterChain<T>();

                boost::container::list<std::string> filterList = PipelineConfigurationParser::Instance()->getFilters(pipelineName, file);

                IFilter<T>* current = NULL;
                BOOST_FOREACH(std::string filterName, filterList)
                {
                    current = AbstractFilter<T>::FilterFactory::createFilterInstance(filterName);

                    if(current != NULL)
                        chain->push_back(current);
                    else
                        fprintf(stderr, "WARNING: Could not find filter: %s\n", filterName.c_str());
                }
                return new ccns::util::PipelineManager<T>(chain);
            }
        };
    }
}

#endif // PIPELINEFACTORY_H
