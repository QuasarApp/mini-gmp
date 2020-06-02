#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.10)
set(CURRENT_PROJECT ${PROJECT_NAME})

project(QtBigint LANGUAGES CXX)

include(../CMake/ProjectOut.cmake)
include(../CMake/Version.cmake)

file(GLOB SOURCE_CPP
    "*.cpp"
    "mini-gmp.c"
)
set_source_files_properties(mini-gmp.c PROPERTIES LANGUAGE CXX )

add_library(${CURRENT_PROJECT} SHARED ${SOURCE_CPP})
target_include_directories(${CURRENT_PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

setVersion(6 1 2)
