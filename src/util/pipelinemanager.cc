#include "pipelinemanager.h"

using namespace ccns::util;

template <class T>
PipelineManager<T>::PipelineManager()
{
    chain = new FilterChain<T>();
}

template <class T>
PipelineManager<T>::PipelineManager(FilterChain<T> *chain)
{
    this->chain = chain;
}

template <class T>
bool PipelineManager<T>::executeChain(T &data, bool stopOnFailure)
{
    bool ret = chain->process(data, stopOnFailure);

    //Todo maybe add a coreprocessor here??

    return ret;
}
