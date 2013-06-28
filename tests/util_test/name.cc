#include <util/name.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::util;

BOOST_AUTO_TEST_SUITE( Name_Test_Suite )

std::string n = "/aau/itec/dposch/file1";

BOOST_AUTO_TEST_CASE( name_constructor_test )
{
    Name name(n);
    BOOST_CHECK_EQUAL(name.getComponents().size(), 4 );

    std::string n2 = name.toString();

    BOOST_CHECK_EQUAL(n2.compare(n), 0);
}

BOOST_AUTO_TEST_SUITE_END()

// EOF
