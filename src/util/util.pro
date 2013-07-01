! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

TARGET = util

LIBS += -lxml2

DESTDIR = lib

HEADERS += \ 
    binarybuffer.h \
    name.h \
    xmlobject.h

SOURCES += \ 
    binarybuffer.cc \
    name.cc \
    xmlobject.cc

