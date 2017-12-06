QT += core
QT -= gui

CONFIG += c++11

TARGET = Lab5
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dictionary.cpp \
    statistics.cpp

HEADERS += \
    dictionary.h \
    statistics.h
