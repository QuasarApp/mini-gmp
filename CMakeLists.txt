#
# Copyright (C) 2018-2021 QuasarApp.
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


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

if(${QT_VERSION_MAJOR})
    add_subdirectory(tests)
endif(${QT_VERSION_MAJOR})

initAll()

addDoc(${PROJECT_NAME}Docs ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)

