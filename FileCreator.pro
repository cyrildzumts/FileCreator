TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -pthread
SOURCES += main.cpp \
    filecreator.cpp

HEADERS += \
    filecreator.h \
    inputargreader.h \
    utils.h \
    queue.h
