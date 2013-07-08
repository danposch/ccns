#include <crypto/dsa.h>
#include <util/binarybuffer.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::crypto;

BOOST_AUTO_TEST_SUITE( DSA_Test_Suite )

BOOST_AUTO_TEST_CASE( Signature_Test )
{

    std::string some_text("This program is free software; you can redistribute it and/or modify "
                          "it under the terms of the GNU Lesser General Public License as published "
                          "by the Free Software Foundation; either version 2.1 of the License, or "
                          "(at your option) any later version.\n"
                          "This program is free software; you can redistribute it and/or modify "
                          "it under the terms of the GNU Lesser General Public License as published "
                          "by the Free Software Foundation; either version 2.1 of the License, or "
                          "(at your option) any later version.\n"
                          "This program is free software; you can redistribute it and/or modify "
                          "it under the terms of the GNU Lesser General Public License as published "
                          "by the Free Software Foundation; either version 2.1 of the License, or "
                          "(at your option) any later version."
                          );

    ccns::util::BinaryBuffer pub, priv;
    ccns::util::BinaryBuffer m(some_text);

    DSA dsa(IDigitalSignature::DSA);

    BOOST_CHECK_EQUAL(dsa.generateKeyPair(&pub, &priv), true);

    ccns::util::BinaryBuffer sig = dsa.sign(m, priv);

    BOOST_CHECK_EQUAL(dsa.verify(m,pub, sig), true);
}

BOOST_AUTO_TEST_SUITE_END()

// EOF

