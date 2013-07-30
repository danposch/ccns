#ifndef ABSTRACTFILTER_H
#define ABSTRACTFILTER_H

#include <boost/unordered_map.hpp>
#include <boost/foreach.hpp>

#include "ifilter.h"

//see http://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name

namespace ccns
{
    namespace util
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
                        return it->second;
                    else
                        return NULL;

                    /*BOOST_FOREACH(typename FilterMap::value_type& pair, getMap())
                        {
                            if(name.compare(pair.first) == 0)
                                return pair.second;
                        }
                    return NULL;*/
                }

            protected:
                static FilterMap* getMap()
                {
                    if(filters != NULL)
                        filters = new FilterMap;
                    return filters;
                }

            private:
                static FilterMap *filters;
            };

            template<typename T>
            struct FilterRegister : FilterFactory
            {
                FilterRegister(const std::string& name)
                {
                    //AbstractFilter<TF>::FilterFactory::FilterMap* fMap = AbstractFilter<TF>::FilterFactory::getMap();
                    //fMap->insert(AbstractFilter<TF>::FilterFactory::FilterMap::value_type(name, &createTemplate<T>));
                    FilterFactory::getMap()->insert(typename FilterFactory::FilterMap::value_type(name, &createTemplate<T>));
                }
            };

            virtual bool process(TF){return true;}

        protected:
        };
    }
}

#endif // ABSTRACTFILTER_H
