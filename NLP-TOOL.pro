TEMPLATE = app
CONFIG += console c++11
CONFIG -= qt

# Définir le compilateur et les options de compilation
QMAKE_CXX = g++
QMAKE_CXXFLAGS += -Wall -g -Iinclude

# Nom de la cible
TARGET = nlpTool

# Répertoires source et build
SRC_DIR = src
BUILD_DIR = build

# Fichiers source
SOURCES += $$files($$SRC_DIR/*.cpp, true)

# Répertoires d'objet
OBJECTS_DIR = $$BUILD_DIR

# Commande pour créer les répertoires d'objets
QMAKE_EXTRA_TARGETS += pre_build
PRE_TARGETDEPS += $$BUILD_DIR
pre_build.commands = mkdir -p $$BUILD_DIR

# Commande de nettoyage
QMAKE_CLEAN += $$TARGET

# PHONY target
QMAKE_EXTRA_TARGETS += phony
phony.target = .PHONY
phony.commands = true

# Spécifier les fichiers source
DISTFILES += $$SRC_DIR/*.cpp