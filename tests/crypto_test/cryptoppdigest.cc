#include <crypto/cryptoppdigest.h>
#include <util/binarybuffer.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::crypto;

unsigned char* sentence = (unsigned char*) "This is a example sentence.";

unsigned char* sentence_sha1 = (unsigned char*) "9B49757F8E9D6010EFC9E9DC385A134357035473";


size_t sentence_length = 27;

BOOST_AUTO_TEST_SUITE( Cryptopp_Digest_Test_Suite )

BOOST_AUTO_TEST_CASE( Digest_Test )
{
   //CryptoppDigest sha1(IDigest::Cryptopp_SHA1);

  //ccns::util::BinaryBuffer buf(sentence, sentence_length);
  //ccns::util::BinaryBuffer dig = sha1.computeDigest(buf);

  //ccns::util::BinaryBuffer buf2 = dig.getHexCopy();

  //fprintf(stderr, "digest length = %s\n", buf2.length());

  //BOOST_CHECK_EQUAL(memcmp((void*) sentence, (void*)buf.getHexCopy().data(), buf.getHexCopy().length()), 0);
  //fprintf(stderr, "digest = %s\n", dig.toHex().data());

}

BOOST_AUTO_TEST_SUITE_END()

// EOF

