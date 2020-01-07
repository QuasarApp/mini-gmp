#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#


QT       -= core gui

TEMPLATE = lib

DEFINES += MINIGMP_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

TARGET = QtBigInt

VERSION = 6.1.2

CONFIG(release, debug|release): {
    DESTDIR="$$PWD/build/release"
} else {
    DESTDIR="$$PWD/build/debug"
}

DISTFILES += \
    README \

HEADERS += \
    bigint.h \
    mini-gmp.h \
    minigmp_global.h

SOURCES += \
    bigint.cpp \
    mini-gmp.c
include(ccache.pri);
