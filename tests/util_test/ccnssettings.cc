#include <util/ccnssettings.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::util;

BOOST_AUTO_TEST_SUITE( CCNSSettings_Test_Suite )

BOOST_AUTO_TEST_CASE( settings_usage_test )
{

    std::string numbers("12345");
    std::string some_text("daniel is testing.");

    CCNSSettings::write("Test.someNumbers", numbers);
    CCNSSettings::write("Test.someText",some_text);

    //CCNSSettings::print();

    std::string res = CCNSSettings::read("Test.someText");

    BOOST_CHECK_EQUAL(memcmp((void*) res.c_str(), (void*)some_text.c_str(),  res.length()), 0);

    res = CCNSSettings::read("Test.someNumbers");
    BOOST_CHECK_EQUAL(memcmp((void*) res.c_str(), (void*)numbers.c_str(),  res.length()), 0);
}

BOOST_AUTO_TEST_SUITE_END()

// EOF
