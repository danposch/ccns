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

            template<typename T> static IFilter<TF>* createTemplate() {return new T;}

            struct FilterFactory
            {
                typedef boost::unordered_map<std::string, IFilter<TF>*(*)()> FilterMap;

                static IFilter<TF>* createFilterInstance(const std::string &name)
                {
                    typename FilterMap::iterator it = getMap()->find(name);
                    if(it != getMap()->end())
                        return it->second();
                    else
                        return NULL;
                }

            protected:
                static FilterMap* getMap()
                {
                    static FilterMap filters;
                    return &filters;
                }
            };

            template<typename T>
            struct FilterRegister : FilterFactory
            {
                FilterRegister(const std::string& name)
                {
                    fprintf(stderr, "Registered Filter: %s\n", name.c_str());
                    FilterFactory::getMap()->insert(typename FilterFactory::FilterMap::value_type(name, &createTemplate<T>));
                }
            };

            virtual bool process(TF *data) = 0;
        };
    }
}

#endif // ABSTRACTFILTER_H
