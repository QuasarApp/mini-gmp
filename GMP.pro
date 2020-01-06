#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
           src

gcc {
    lessThan (QT_MINOR_VERSION, 12) {
        message(disable tests!)
    } else {
        include($$PWD/tests/test.pri)
        message(enabled tests!)
        SUBDIRS += tests
        SUBDIRS += tests
        tests.file = tests/tests.pro
    }
}

src.file = src/GMP.pro

