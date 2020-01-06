#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

!isEmpty(CCACHE_INCLUDE):error("ccache.pri already included")
CCACHE_INCLUDE = 1

contains(QMAKE_HOST.os, Linux):{
    BIN = $$system(which ccache)

    !isEmpty(BIN) {
        message(ccache detected in $$BIN)
        QMAKE_CXX='$$BIN $$QMAKE_CXX'
    }
}




