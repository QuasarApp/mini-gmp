#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

!isEmpty(Qt_GMP_LIB):error("GMP.pri already included")
Qt_GMP_LIB = 1

#DEPENDS
CONFIG(release, debug|release): {
    MINIGMP_LIBRARY_OUTPUT_DIR="$$PWD/build/release"
} else {
    MINIGMP_LIBRARY_OUTPUT_DIR="$$PWD/build/debug"
}

lessThan (QT_MINOR_VERSION, 14): {
    unix: LIBS += -L$$MINIGMP_LIBRARY_OUTPUT_DIR -lQtBigInt
    win32: LIBS += -L$$MINIGMP_LIBRARY_OUTPUT_DIR -lQtBigInt6

} else {
    LIBTENP = -L$$MINIGMP_LIBRARY_OUTPUT_DIR -lQtBigInt
    android: LIBTENP = -L$$MINIGMP_LIBRARY_OUTPUT_DIR -lQtBigInt_$$QT_ARCH
    win32: LIBTENP = -L$$MINIGMP_LIBRARY_OUTPUT_DIR -lQtBigInt6

    LIBS += $$LIBTENP
}

message(LIBS = $$LIBS)


include(GMPIncudePah.pri)
include(ccache.pri);
