#include "samplefilter.h"

using namespace ccns::processing;

//typename ccns::processing::AbstractFilter<std::string>::FilterRegister<SampleFilter> SampleFilter::reg(std::string("SampleFilter"));

SampleFilter::SampleFilter()
{
}

bool SampleFilter::process(std::string *data)
{
    fprintf(stderr, "Processcing Data = %s...\n",data->c_str());
    return true;
}
