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
    cryptoppdigest.h

SOURCES += \
    abstractdigest.cc \
    cryptoppdigest.cc
