#include <processing_pipes/filterchain.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/container/list.hpp>
#include <boost/foreach.hpp>

#include <string.h>

#include <processing_pipes/pipelineconfigurationparser.h>
#include <processing_pipes/pipelinemanager.hpp>
#include <processing_pipes/pipelinefactory.hpp>

//#include <processing_pipes/filters/samplefilter.h>

#include <processing_pipes/abstractfilter.hpp>

using namespace ccns::processing;

#include <stdio.h>

BOOST_AUTO_TEST_SUITE( CCNS_Filter_Tests )

BOOST_AUTO_TEST_CASE( some_tests )
{
    std::string pipelinename = "pipeline2";
    std::string file = "/home/dposch/ccns/tests/util_test/filters.config";
    //SampleFilter fff;
    //boost::container::list<std::string> list = PipelineConfigurationParser::Instance()->getFilters(pipelinename,file);

    PipelineManager<std::string> *man = PipelineFactory<std::string>::CreateFromConfig(pipelinename,file);

    IFilter<std::string>* f = AbstractFilter<std::string>::createFilterInstance("SampleFilter");

    std::string data("thats a test string");

    man->executeChain(&data);

    /*
    BOOST_FOREACH(std::string s, list)
    {
        fprintf(stderr, "Result = %s\n", s.c_str());
    }*/
    //SampleFilter ff;
}

BOOST_AUTO_TEST_SUITE_END()

// EOF
