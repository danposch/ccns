! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

TARGET = util

DESTDIR = lib

HEADERS += \ 
    binarybuffer.h \
    name.h

SOURCES += \ 
    binarybuffer.cc \
    name.cc

