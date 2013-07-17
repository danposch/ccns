#ifndef PIPELINEFACTORY_H
#define PIPELINEFACTORY_H

#include <string.h>

#include "pipelinemanager.h"

namespace ccns
{
    namespace util
    {
        class PipelineFactory
        {
        public:
            template <class T>
            static PipelineManager<T> *CreateFromConfig(const std::string &pipelineName, const std::string &file);
        };
    }
}

#endif // PIPELINEFACTORY_H
