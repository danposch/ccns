#include <crypto/cryptoppdigest.h>
#include <util/binarybuffer.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::crypto;

unsigned char* sentence = (unsigned char*) "This is a example sentence.";
unsigned char* sentence_sha1 = (unsigned char*) "9B49757F8E9D6010EFC9E9DC385A134357035473";
unsigned char* sentence_ripemd160 = (unsigned char*) "D6C8EC5A0D047FDAA61F3BD89F9F29840D3B8150";
unsigned char* sentence_sha3_256 = (unsigned char*) "7AD0671AEDF4E37B3D57135C49F222647148D672D4FED92B988D2816E71BF752";

size_t sentence_length = 27;

BOOST_AUTO_TEST_SUITE( Cryptopp_Digest_Test_Suite )

BOOST_AUTO_TEST_CASE( Digest_Test )
{
  ccns::util::BinaryBuffer buf(sentence, sentence_length);

  CryptoppDigest sha1(IDigest::Cryptopp_SHA1);
  ccns::util::BinaryBuffer dig = sha1.computeDigest(buf);
  BOOST_CHECK_EQUAL(dig.length(), sha1.getDigestLength());

  ccns::util::BinaryBuffer hex = dig.getHexCopy();
  BOOST_CHECK_EQUAL(memcmp((void*) sentence_sha1, (void*)hex.data(), hex.length()), 0);


  CryptoppDigest ripemd160(IDigest::Cryptopp_RIPEMD160);
  dig = ripemd160.computeDigest(buf);
  BOOST_CHECK_EQUAL(dig.length(), ripemd160.getDigestLength());

  hex = dig.getHexCopy();
  BOOST_CHECK_EQUAL(memcmp((void*) sentence_ripemd160, (void*)hex.data(), hex.length()), 0);

  CryptoppDigest sha3_256(IDigest::Cryptopp_SHA3_256);
  dig = sha3_256.computeDigest(buf);
  BOOST_CHECK_EQUAL(dig.length(), sha3_256.getDigestLength());

  hex = dig.getHexCopy();
  BOOST_CHECK_EQUAL(memcmp((void*) sentence_sha3_256, (void*)hex.data(), hex.length()), 0);
}

BOOST_AUTO_TEST_SUITE_END()

// EOF

