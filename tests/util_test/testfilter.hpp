/*#ifndef TESTFILTER_HPP
#define TESTFILTER_HPP

#include <string.h>

#include "util/abstractfilter.hpp"

#include <fstream>

    class TestFilter : public ccns::util::AbstractFilter<std::string>
    {
        public:
            TestFilter();
            bool process(std::string *data);

        private:
            static FilterRegister<TestFilter> reg;
    };

    typename ccns::util::AbstractFilter<std::string>::FilterRegister<TestFilter> TestFilter::reg(std::string("TestFilter"));

#endif // TESTFILTER_HPP*/
