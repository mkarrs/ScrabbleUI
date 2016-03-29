#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T18:38:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scrabble
TEMPLATE = app


SOURCES += main.cpp\
        scrabble.cpp \
    game_objects.cpp \
    tile.cpp

HEADERS  += scrabble.h \
    tile.h

FORMS    += scrabble.ui
