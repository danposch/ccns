#include "samplefilter.h"

using namespace ccns::processing;

//typename ccns::processing::AbstractFilter<std::string>::FilterRegister<SampleFilter> SampleFilter::reg(std::string("SampleFilter"));

AbstractFilter<std::string>::FilterRegister SampleFilter::reg("SampleFilter", SampleFilter::create);

SampleFilter::SampleFilter()
{
}

bool SampleFilter::process(std::string *data)
{
    fprintf(stderr, "Duplicating Data = %s\n",data->c_str());
    data->append(*data);
    return true;
}
