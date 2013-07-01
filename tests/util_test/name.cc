#include <util/name.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::util;

BOOST_AUTO_TEST_SUITE( Name_Test_Suite )

std::string file1 = "/aau/itec/dposch/file1";
std::string file2 = "/aau/itec/dposch/file2";

BOOST_AUTO_TEST_CASE( name_constructor_test )
{
    Name n1(file1);
    BOOST_CHECK_EQUAL(n1.getComponents().size(), 4 );

    std::string res_str = n1.toString();

    BOOST_CHECK_EQUAL(res_str.compare(file1), 0);

    Name n2 = n1;
    BOOST_CHECK_EQUAL(n1.toString().compare(n2.toString()), 0);

    n1 = file2;
    BOOST_CHECK_EQUAL(file2.compare(n1.toString()), 0);
    BOOST_CHECK_EQUAL(file1.compare(n2.toString()), 0);

    Name n3(n1);
    n1 = n2;
    BOOST_CHECK_EQUAL(file2.compare(n3.toString()), 0);
}

BOOST_AUTO_TEST_SUITE_END()

// EOF
