#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

unix:exec = $$PWD/build/release/QtBigIntTests
win32:exec = $$PWD/build/release/QtBigIntTests.exe

QT_DIR = $$[QT_HOST_BINS]
win32:QMAKE_BIN = $$QT_DIR/qmake.exe

contains(QMAKE_HOST.os, Linux):{
    DEPLOYER=cqtdeployer
    QMAKE_BIN = $$QT_DIR/qmake

} else {
    DEPLOYER=%cqtdeployer%
}

deployTest.commands = $$DEPLOYER -bin $$exec clear -qmake $$QMAKE_BIN -targetDir $$PWD/deployTests -libDir $$PWD -recursiveDepth 5

unix:test.commands = $$PWD/deployTests/QtBigIntTests.sh
win32:test.commands = $$PWD/deployTests/QtBigIntTests.exe

contains(QMAKE_HOST.os, Linux):{
    DEPLOYER=cqtdeployer
    win32:test.commands = wine $$PWD/deployTests/QtBigIntTests.exe

} else {
    DEPLOYER=%cqtdeployer%
}

test.depends += deployTest

QMAKE_EXTRA_TARGETS += \
    deployTest \
    test
