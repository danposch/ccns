#include <util/filterchain.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/container/list.hpp>
#include <boost/foreach.hpp>

#include <string.h>

#include <util/pipelineconfigurationparser.h>
#include <util/pipelinemanager.hpp>
#include <util/pipelinefactory.hpp>

#include <util/samplefilter.h>

using namespace ccns::util;


#include <stdio.h>

BOOST_AUTO_TEST_SUITE( CCNS_Filter_Tests )

BOOST_AUTO_TEST_CASE( some_tests )
{

    std::string pipelinename = "pipeline2";
    std::string file = "/home/dposch/ccns/tests/util_test/filters.config";

    //boost::container::list<std::string> list = PipelineConfigurationParser::Instance()->getFilters(pipelinename,file);

    PipelineManager<std::string> *man = PipelineFactory<std::string>::CreateFromConfig(pipelinename,file);

    SampleFilter f;

    std::string data("thats a test string");
    man->executeChain(&data);

    /*
    BOOST_FOREACH(std::string s, list)
    {
        fprintf(stderr, "Result = %s\n", s.c_str());
    }*/

}

BOOST_AUTO_TEST_SUITE_END()

// EOF
