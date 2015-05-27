#include <processing_pipes/filterchain.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/container/list.hpp>
#include <boost/foreach.hpp>

#include <string.h>

#include <processing_pipes/pipelinemanager.hpp>
#include <processing_pipes/pipelinefactory.hpp>

using namespace ccns::processing;

#include <stdio.h>

BOOST_AUTO_TEST_SUITE( CCNS_Filter_Tests )

BOOST_AUTO_TEST_CASE( Basic_Filter_Test )
{
    std::string pipelinename_notexist = "DoesNotExistPipeline";
    std::string pipelinename = "TestPipeline";
    std::string data("duplicate_me.");
    std::string expectedResult("duplicate_me.duplicate_me.duplicate_me.duplicate_me.");
    std::string file = "/home/dposch/ccns/tests/processing_pipes_test/filters.config";

    PipelineManager<std::string> *man = PipelineFactory<std::string>::CreateFromConfig(pipelinename_notexist,file);
    man->executeChain(&data);

    delete(man);

    man = PipelineFactory<std::string>::CreateFromConfig(pipelinename,file);
    man->executeChain(&data);

    BOOST_CHECK_EQUAL(memcmp((void*) expectedResult.c_str(), (void*)data.c_str(), expectedResult.size()), 0);

}

BOOST_AUTO_TEST_CASE( some_test)
{

}

BOOST_AUTO_TEST_SUITE_END()

// EOF
