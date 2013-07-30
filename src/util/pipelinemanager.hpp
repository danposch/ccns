#ifndef PIPELINEMANAGER_H
#define PIPELINEMANAGER_H

#include "filterchain.hpp"

namespace ccns
{
    namespace util
    {
        template<typename T>
        class PipelineManager
        {
        public:
            PipelineManager(){chain = new FilterChain<T>();}
            PipelineManager(FilterChain<T> *chain){this->chain = chain;}

            bool executeChain(T &data, bool stopOnFailure = false)
            {
                bool ret = chain->process(data, stopOnFailure);

                //Todo maybe add a coreprocessor here??

                return ret;
            }

        private:
            FilterChain<T> *chain;

        };
    }
}
#endif // PIPELINEMANAGER_H
