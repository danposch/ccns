#ifndef ABSTRACTFILTER_H
#define ABSTRACTFILTER_H

#include <boost/unordered_map.hpp>
#include <boost/foreach.hpp>

#include "ifilter.h"
#include <fstream>

//see http://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name

namespace ccns
{
    namespace processing
    {
        template<typename TF>
        class AbstractFilter : public IFilter<TF>
        {
        public:

            typedef AbstractFilter *(*ifilter_creator_fn)();

            //template<typename T> static IFilter<TF>* createTemplate() {return new T;}

            virtual ~AbstractFilter(){}

            typedef boost::unordered_map<std::string, ifilter_creator_fn> FilterMap;

            static IFilter<TF>* createFilterInstance(const std::string &name)
            {
                typename FilterMap::iterator it = getMap().find(name);
                if(it != getMap().end())
                    return it->second();
                else
                    return NULL;
            }

            static FilterMap& getMap()
            {
                static FilterMap filters;
                return filters;
            }

            struct FilterRegister
            {
                FilterRegister(const std::string &name, AbstractFilter<TF>::ifilter_creator_fn function)
                {
                    fprintf(stderr, "Registered Filter: %s\n", name.c_str());
                    getMap().insert(typename FilterMap::value_type(name, function));
                }
            };

            virtual bool process(TF *data) = 0;
        };
    }
}

#endif // ABSTRACTFILTER_H
