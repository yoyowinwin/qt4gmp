
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
HEADERS += qtgmp.hpp
SOURCES += main.cpp qtgmp.cpp
LIBS+=-lgmp 

RC_FILE     = snippets.rc
