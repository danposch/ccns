#include <util/binarybuffer.h>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace ccns::util;

BOOST_AUTO_TEST_SUITE( BinaryBuffer_Test_Suite )

unsigned char* word1 = (unsigned char*) "the ";
unsigned char* word2 = (unsigned char*) "old ";
unsigned char* word3 = (unsigned char*) "fox ";
unsigned char* word4 = (unsigned char*) "is running.";
unsigned char* phrase = (unsigned char*) "the old fox is running.";

size_t phrase_length = 23;


BOOST_AUTO_TEST_CASE( binarybuffer_constructor_test )
{
     BinaryBuffer empty;
     BOOST_CHECK_EQUAL(empty.length(), (size_t) 0 );

     BinaryBuffer empty2 = BinaryBuffer(empty);
     BOOST_CHECK_EQUAL(empty2.length(), (size_t) 0 );

     BinaryBuffer buffer1(word1, (size_t) 4);
     BOOST_CHECK_EQUAL(buffer1.length(), (size_t) 4 );
     BOOST_CHECK_EQUAL(memcmp((void*) buffer1.data(), (void*)word1, buffer1.length()), 0);

     BinaryBuffer buffer2 = BinaryBuffer(buffer1);
     BOOST_CHECK_EQUAL(buffer2.length(), buffer1.length());
     BOOST_CHECK_EQUAL(memcmp((void*) buffer2.data(), (void*)buffer1.data(), buffer1.length()), 0);
}

BOOST_AUTO_TEST_CASE( binarybuffer_usage_test )
{

    BinaryBuffer buffer1(word1, (size_t) 4);
    buffer1.append(word2, (size_t) 4).append(word3, (size_t) 4).append(word4, (size_t) 11);

    BOOST_CHECK_EQUAL(buffer1.length(), phrase_length );
    BOOST_CHECK_EQUAL(memcmp((void*) buffer1.data(), (void*)phrase,  phrase_length), 0);

    BinaryBuffer buffer2;

    buffer2 + buffer1;
    BOOST_CHECK_EQUAL(buffer2.length(), (size_t) 0 );

    buffer2 = buffer2 + buffer1;
    BOOST_CHECK_EQUAL(buffer2.length(), buffer1.length() );
    BOOST_CHECK_EQUAL(memcmp((void*) buffer1.data(), (void*)buffer2.data(),  buffer1.length()), 0);

    buffer2.clear();
    BOOST_CHECK_EQUAL(buffer2.length(), (size_t) 0 );

    buffer2.append(buffer1);
    BOOST_CHECK_EQUAL(buffer2.length(), buffer1.length() );
    BOOST_CHECK_EQUAL(memcmp((void*) buffer1.data(), (void*)buffer2.data(),  buffer1.length()), 0);
}

unsigned char* sentence = (unsigned char*)
                            "Base64 is an encoding scheme used to represent binary data in "
                            "an ASCII format. Thats great!";

unsigned char* sentence_base64 = (unsigned char*)
                           "QmFzZTY0IGlzIGFuIGVuY29kaW5nIHNjaGVtZSB1c2VkIHRvIHJlcHJlc2VudCBiaW"
                            "5hcnkgZGF0YSBpbiBhbiBBU0NJSSBmb3JtYXQuIFRoYXRzIGdyZWF0IQ==";

unsigned char* sentence_hex = (unsigned char*)
                           "42617365363420697320616E20656E636F64696E6720736368656D652075736564"
                           "20746F20726570726573656E742062696E617279206461746120696E20616E2041"
                           "5343494920666F726D61742E20546861747320677265617421";


unsigned char* some_text = (unsigned char*)
                            "This program is free software; you can redistribute it and/or modify "
                           "it under the terms of the GNU Lesser General Public License as published "
                           "by the Free Software Foundation; either version 2.1 of the License, or "
                           "(at your option) any later version.";

size_t sentence_length = 91;
size_t sentence_base64_length = 124;
size_t sentence_hex_length = 182;
size_t some_text_length = 249;

BOOST_AUTO_TEST_CASE( binarybuffer_base64_test )
{
    BinaryBuffer buffer(sentence, sentence_length);
    BOOST_CHECK_EQUAL(buffer.getBase64Copy().length(), sentence_base64_length );
    BOOST_CHECK_EQUAL(memcmp((void*) buffer.getBase64Copy().data(), (void*)sentence_base64,  sentence_base64_length), 0);
    BOOST_CHECK_EQUAL(memcmp((void*) buffer.toBase64().data(), (void*)sentence_base64,  sentence_base64_length), 0);

    buffer.clear();
    buffer.append(some_text, some_text_length);

    buffer.toBase64();
    buffer.fromBase64();
    BOOST_CHECK_EQUAL(memcmp((void*) buffer.data(), (void*)some_text, some_text_length), 0);
    BOOST_CHECK_EQUAL(buffer.length(), some_text_length );
}

BOOST_AUTO_TEST_CASE( binarybuffer_hex_test )
{
    BinaryBuffer buffer(sentence, sentence_length);
    BOOST_CHECK_EQUAL(buffer.getHexCopy().length(), sentence_hex_length );
    BOOST_CHECK_EQUAL(memcmp((void*) buffer.getHexCopy().data(), (void*)sentence_hex,  sentence_hex_length), 0);
    BOOST_CHECK_EQUAL(memcmp((void*) buffer.toHex().data(), (void*)sentence_hex,  sentence_hex_length), 0);

    buffer.clear();
    buffer.append(some_text, some_text_length);

    buffer.toHex();
    buffer.fromHex();
    BOOST_CHECK_EQUAL(memcmp((void*) buffer.data(), (void*)some_text, some_text_length), 0);
    BOOST_CHECK_EQUAL(buffer.length(), some_text_length );
}

BOOST_AUTO_TEST_SUITE_END()

// EOF
