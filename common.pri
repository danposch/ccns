#Includes common configuration for all subdirectory .pro files.

# to build the release version call qmake CONFIG+=ccns_release
CONFIG -= debug_and_release
CONFIG -= release
CONFIG += debug

contains(CONFIG, ccns_release) {
	CONFIG -= debug
	CONFIG += release
}

CONFIG(debug, debug|release) {
    message( "Building the DEBUG Version" )
} else {
    message( "Building the RELEASE Version" )
}

INCLUDEPATH =  \
               /usr/local/include/ \
               /usr/include/ \
               ./../util/

LIBS = -L/usr/local/lib \
       -L/usr/lib \
        -lpthread


CONFIG -= qt
CONFIG += warn_on

WARNINGS += -Wall

DESTDIR = bin
OBJECTS_DIR = build
