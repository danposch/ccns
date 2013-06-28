#include <util/binarybuffer.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::util;

BOOST_AUTO_TEST_SUITE( BinaryBuffer_Test_Suite )

unsigned char* word1 = (unsigned char*) "the ";
unsigned char* word2 = (unsigned char*) "old ";
unsigned char* word3 = (unsigned char*) "fox ";
unsigned char* word4 = (unsigned char*) "is running.";
unsigned char* sentence = (unsigned char*) "the old fox is running.";
unsigned char* sentence_base64 = (unsigned char*) "dGhlIG9sZCBmb3ggaXMgcnVubmluZy4=";

unsigned char* some_text = (unsigned char*)
                            "This program is free software; you can redistribute it and/or modify "
                           "it under the terms of the GNU Lesser General Public License as published "
                           "by the Free Software Foundation; either version 2.1 of the License, or "
                           "(at your option) any later version.";

size_t sentence_length = 23;
size_t some_text_length = 249;

BOOST_AUTO_TEST_CASE( binarybuffer_constructor_test )
{
     BinaryBuffer empty;
     BOOST_CHECK_EQUAL(empty.length(), (size_t) 0 );

     BinaryBuffer empty2 = BinaryBuffer(empty);
     BOOST_CHECK_EQUAL(empty2.length(), (size_t) 0 );

     BinaryBuffer buffer1(word1, (size_t) 4);
     BOOST_CHECK_EQUAL(buffer1.length(), (size_t) 4 );

     BinaryBuffer buffer2 = BinaryBuffer(buffer1);
     BOOST_CHECK_EQUAL(buffer2.length(), buffer1.length());

}

BOOST_AUTO_TEST_CASE( binarybuffer_usage_test )
{

    BinaryBuffer buffer1(word1, (size_t) 4);
    buffer1.append(word2, (size_t) 4).append(word3, (size_t) 4).append(word4, (size_t) 11);

    BOOST_CHECK_EQUAL(buffer1.length(), sentence_length );
    BOOST_CHECK_EQUAL(memcmp((void*) buffer1.data(), (void*)sentence,  sentence_length), 0);

    BinaryBuffer buffer2;
    buffer2 + buffer1;

    BOOST_CHECK_EQUAL(buffer2.length(), (size_t) 0 );

    buffer2 = buffer2 + buffer1;
    BOOST_CHECK_EQUAL(buffer2.length(), buffer1.length() );
    BOOST_CHECK_EQUAL(memcmp((void*) buffer1.data(), (void*)buffer2.data(),  buffer1.length()), 0);

    BinaryBuffer buffer3 = BinaryBuffer(some_text, some_text_length);
    buffer3.toBase64();
    buffer3.fromBase64();

    BOOST_CHECK_EQUAL(memcmp((void*) buffer3.data(), (void*)some_text,  buffer3.length()), 0);
}


BOOST_AUTO_TEST_SUITE_END()

// EOF
