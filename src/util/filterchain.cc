#include "filterchain.h"

using namespace ccns::util;

template <class T>
FilterChain<T>::FilterChain()
{
}

template <class T>
bool FilterChain<T>::process(T &data, bool stopOnFailure)
{
    bool ret = true;

    BOOST_FOREACH(IFilter <T> filter, this)
    {
        if ( !(filter->Process(data)) )
        {
            ret = false;

            if(stopOnFailure)
                break;
        }
    }
    return ret;
}
