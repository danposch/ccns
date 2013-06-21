#Includes common configuration for all subdirectory .pro files.

#todo find solution
CONFIG -= debug_and_release
CONFIG -= release

CONFIG(debug, debug|release) {
    message( "debug" )
} else {
    message( "release" )
}

INCLUDEPATH += . ..
LIBS += -L/usr/lib

CONFIG += warn_on
WARNINGS += -Wall

CONFIG -= qt

DESTDIR = bin
OBJECTS_DIR = build

#LIBS += -lboost_regex
