#ifndef PIPELINEMANAGER_H
#define PIPELINEMANAGER_H

#include "filterchain.h"

namespace ccns
{
    namespace util
    {
        template<typename T>
        class PipelineManager
        {
        public:
            PipelineManager();
            PipelineManager(FilterChain<T> *chain);

            bool executeChain(T &data, bool stopOnFailure = false);

        private:
            FilterChain<T> *chain;

        };
    }
}

#endif // PIPELINEMANAGER_H
