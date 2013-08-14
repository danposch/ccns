! include( $$_PRO_FILE_PWD_/../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = app

INCLUDEPATH += ../src/ ../src/util ../src/crypto ../src/encoding ../src/processing_pipes

HEADERS += \

SOURCES +=  test_main.cc \
            util_test/binarybuffer.cc \
            util_test/name.cc \
            util_test/ccnssettings.cc \
            processing_pipes_test/filters.cc \
            encoding_test/packetmanager.cc \
            crypto_test/cryptoppdigest.cc \
            crypto_test/dsa.cc \
            ../src/processing_pipes/filters/samplefilter.cc

LIBS += -lboost_unit_test_framework \
        ../src/crypto/lib/libccns_crypto.a \
        ../src/util/lib/libccns_util.a \
        ../src/processing_pipes/lib/libccns_processing_pipes.a \
        -lcryptopp \
        -lboost_system \
        -lboost_filesystem \
        -lxml2

#LIBS += ../src/processing_pipes/build/samplefilter.o
