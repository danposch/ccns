#ifndef FILTERCHAIN_H
#define FILTERCHAIN_H

#include <boost/container/list.hpp>
#include <boost/foreach.hpp>

#include "ifilter.h"

namespace ccns
{
    namespace util
    {
        template <typename T>
        class FilterChain : public boost::container::list<IFilter<T> *>
        {
        public:
            FilterChain(){}

            bool process(T *data, bool stopOnFailure = false)
            {
                bool ret = true;

                BOOST_FOREACH(IFilter<T> *filter, *this)
                {
                    if ( !(filter->process(data)) )
                    {
                        ret = false;

                        if(stopOnFailure)
                            break;
                    }
                }
                return ret;
            }
        };
    }
}
#endif // FILTERCHAIN_H
