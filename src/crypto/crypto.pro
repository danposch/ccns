! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

DESTDIR = lib
TARGET = crypto

LIBS += ./../util/lib/libutil.a \
        -lcryptopp

HEADERS += \
    icipher.h \
    idigest.h \
    abstractdigest.h \
    cryptoppdigest.h \
    ikeystore.h \
    abstractcipher.h \
    idigitalsignature.h \
    abstractdigitalsignature.h \
    dsa.h

SOURCES += \
    abstractdigest.cc \
    cryptoppdigest.cc \
    abstractcipher.cc \
    abstractdigitalsignature.cc \
    dsa.cc
