! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = app

LIBS += ./../util/lib/libutil.a -lcryptopp

HEADERS += \
    packetmanager.h \
    packetbuilderfactory.h \
    ipacket.h \
    abstractpacket.h \
    ipacketbuilder.h \
    abstractpacketbuilder.h \
    ccnxinterstbuilder.h \
    ccnxinterest.h \
    ccnxcontentobjectbuilder.h \
    ccnxcontentobject.h


SOURCES += main.cc \
    packetmanager.cc \
    packetbuilderfactory.cc \
    abstractpacket.cc \
    abstractpacketbuilder.cc \
    ccnxinterstbuilder.cc \
    ccnxinterest.cc \
    ccnxcontentobjectbuilder.cc \
    ccnxcontentobject.cc
