QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = nlpTool


BUILD_DIR = $$PWD/build
SRC_DIR = src
HEADER_DIR = include
SOURCES += $$files($$SRC_DIR/*.cpp, true)
HEADERS += $$files($$HEADER_DIR/*.hh, true)
HEADERS += include/gui/ui_mainwindow.h

FORMS += \
    src/gui/mainwindow.ui

OBJECTS_DIR = $$BUILD_DIR

INCLUDEPATH += $$PWD/include

UI_DIR = $$PWD/include/gui

QMAKE_EXTRA_TARGETS += pre_build
PRE_TARGETDEPS += $$BUILD_DIR
pre_build.commands = mkdir -p $$BUILD_DIR

QMAKE_CLEAN += $$TARGET

QMAKE_EXTRA_TARGETS += phony
phony.target = .PHONY
phony.commands = true

DISTFILES += $$SRC_DIR/*.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
