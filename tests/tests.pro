! include( $$_PRO_FILE_PWD_/../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = app

LIBS += -lboost_unit_test_framework \
        ../src/crypto/lib/libccns_crypto.a \
        ../src/util/lib/libccns_util.a \
        -lcryptopp \
        -lboost_system \
        -lboost_filesystem

INCLUDEPATH += ../src/ ../src/util ../src/crypto .. src/encoding

HEADERS += \

SOURCES +=  test_main.cc \
            util_test/binarybuffer.cc \
            util_test/name.cc \
            util_test/ccnssettings.cc \
            encoding_test/packetmanager.cc \
            crypto_test/cryptoppdigest.cc \
            crypto_test/dsa.cc
