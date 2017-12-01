cmake_minimum_required(VERSION 3.8)
project(HW4_5_6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp bTREE.h bTREE.cpp pMT.cpp pMT.h vote.cpp)
add_executable(HW4_5_6 ${SOURCE_FILES})