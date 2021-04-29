#
# Copyright (C) 2018-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.10)
set(CURRENT_PROJECT ${PROJECT_NAME})

project(QtBigint LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_CPP
    "*.cpp"
    "mini-gmp.c"
)
set_source_files_properties(mini-gmp.c PROPERTIES LANGUAGE CXX )

add_library(${CURRENT_PROJECT} ${SOURCE_CPP})
target_include_directories(${CURRENT_PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

setVersion(6 1 2)
