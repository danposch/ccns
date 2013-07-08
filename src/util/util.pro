! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

DESTDIR = lib
TARGET = ccns_util

LIBS += -lxml2


HEADERS += \ 
    binarybuffer.h \
    name.h \
    xmlobject.h

SOURCES += \ 
    binarybuffer.cc \
    name.cc \
    xmlobject.cc

