#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.10)
project(QtBigint LANGUAGES CXX)
if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()

include(CMake/ccache.cmake)
include(CMake/QuasarAppCITargets.cmake)


# Add sub directories
add_subdirectory(src)

find_library(QT Qt5Core)

if(EXISTS ${QT})
    add_subdirectory(tests)
endif(EXISTS ${QT})

initAll()
