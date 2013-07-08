#include <crypto/dsa.h>
#include <util/binarybuffer.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::crypto;

BOOST_AUTO_TEST_SUITE( DSA_Test_Suite )

BOOST_AUTO_TEST_CASE( Key_Generation )
{

    std::string sentence ("This is a example sentence and it will be signed.");

    ccns::util::BinaryBuffer pub, priv;
    ccns::util::BinaryBuffer m(sentence);

    DSA dsa(IDigitalSignature::DSA);

    BOOST_CHECK_EQUAL(dsa.generateKeyPair(&pub, &priv), true);

    //dsa.sign
}

BOOST_AUTO_TEST_SUITE_END()

// EOF

