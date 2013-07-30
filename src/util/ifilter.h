#ifndef IFILTER_H
#define IFILTER_H

namespace ccns
{
    namespace util
    {
        template <typename T>
        class IFilter
        {
        public:

            virtual ~IFilter(){}
            virtual bool process(T data) = 0;
        };
    }
}

#endif // IFILTER_H
