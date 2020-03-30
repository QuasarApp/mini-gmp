#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.1)
include(../CMake/crossplatform/crossplatform.cmake)

project(QtBigint LANGUAGES CXX)

include(../CMake/ProjectOut.cmake)
include(../CMake/Version.cmake)

file(GLOB SOURCE_CPP
    "*.cpp"
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_CPP})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

setVersion(6 1 2)
