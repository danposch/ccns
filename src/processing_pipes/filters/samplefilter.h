#ifndef SAMPLEFILTER_H
#define SAMPLEFILTER_H

#include <string.h>

#include "../abstractfilter.hpp"

#include <fstream>

namespace ccns
{
    namespace processing
    {
        class SampleFilter : public AbstractFilter<std::string>
        {
            public:
                SampleFilter();
                bool process(std::string *data);

                static AbstractFilter<std::string>* create(){return new SampleFilter;}

            private:
                static FilterRegister reg;
        };
    }
}

#endif // SAMPLEFILTER_H
