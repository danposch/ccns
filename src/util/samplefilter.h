#ifndef SAMPLEFILTER_H
#define SAMPLEFILTER_H

#include <string.h>

#include "abstractfilter.hpp"

namespace ccns
{
    namespace util
    {
    class SampleFilter : public AbstractFilter<std::string>
    {
        public:
            SampleFilter();
            bool process(std::string data);

        private:
            static FilterRegister<SampleFilter> reg;
    };
    }
}

#endif // SAMPLEFILTER_H
