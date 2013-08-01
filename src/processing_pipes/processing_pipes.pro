! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

DESTDIR = lib
TARGET = ccns_processing_pipes

LIBS += -lxml2 \
        -lboost_system \
        -lboost_filesystem

#Pattern
HEADERS += \ 
    ifilter.h \
    pipelineconfigurationparser.h \
    pipelinefactory.hpp \
    abstractfilter.hpp \
    filterchain.hpp \
    pipelinemanager.hpp

SOURCES += \ 
    pipelineconfigurationparser.cc \

#Filters
HEADERS += \
    filters/samplefilter.h \

SOURCES += \
    filters/samplefilter.cc \


