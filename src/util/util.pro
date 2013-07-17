! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

DESTDIR = lib
TARGET = ccns_util

LIBS += -lxml2 \
        -lboost_system \
        -lboost_filesystem


HEADERS += \ 
    binarybuffer.h \
    name.h \
    xmlobject.h \
    ccnssettings.h \
    ifilter.h \
    filterchain.h \
    pipelinemanager.h \
    pipelinefactory.h \
    pipelineconfigurationparser.h

SOURCES += \ 
    binarybuffer.cc \
    name.cc \
    xmlobject.cc \
    ccnssettings.cc \
    filterchain.cc \
    pipelinefactory.cc \
    pipelinemanager.cc \
    pipelineconfigurationparser.cc

