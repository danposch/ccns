! include( $$_PRO_FILE_PWD_/../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = app

LIBS += -lboost_unit_test_framework \
        ../src/crypto/lib/libcrypto.a \
        ../src/util/lib/libutil.a \
        -lcryptopp

INCLUDEPATH += ../src/ ../src/util ../src/crypto .. src/encoding

HEADERS += \

SOURCES += test_main.cc \
           util_test/binarybuffer.cc \
           util_test/name.cc \
           encoding_test/packetmanager.cc \
           crypto_test/cryptoppdigest.cc
