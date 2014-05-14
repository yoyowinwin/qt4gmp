
TEMPLATE = app
TARGET = Qt4gmp
INCLUDEPATH += .

OBJECTS_DIR	= build
MOC_DIR         = build
RCC_DIR		= build
CONFIG-=debug_and_release 
CONFIG+=release

#CONFIG += console
QT += widgets
# Input
INCLUDEPATH = /opt/arm/include
HEADERS += qtgmp.hpp
SOURCES += main.cpp qtgmp.cpp
#LIBS+= -I/opt/arm/include -L/opt/arm/lib -lgmp
LIBS+= -lgmp

RC_FILE     = snippets.rc
