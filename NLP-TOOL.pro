TEMPLATE = app
CONFIG += console c++11
CONFIG -= qt

QMAKE_CXX = g++
QMAKE_CXXFLAGS += -Wall -g -Iinclude

TARGET = nlpTool

SRC_DIR = src
BUILD_DIR = build

SOURCES += $$files($$SRC_DIR/*.cpp, true)

OBJECTS_DIR = $$BUILD_DIR

QMAKE_EXTRA_TARGETS += pre_build
PRE_TARGETDEPS += $$BUILD_DIR
pre_build.commands = mkdir -p $$BUILD_DIR

QMAKE_CLEAN += $$TARGET

QMAKE_EXTRA_TARGETS += phony
phony.target = .PHONY
phony.commands = true

DISTFILES += $$SRC_DIR/*.cpp