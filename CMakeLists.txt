#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.1)
project(MainQtBigint)

include(CMake/ccache.cmake)
include(CMake/QuasarAppCITargets.cmake)

initAll()

# Add sub directories
add_subdirectory(src)
add_subdirectory(tests)
