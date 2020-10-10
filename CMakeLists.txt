cmake_minimum_required(VERSION 3.17)
project(TimurDZ)

set(CMAKE_CXX_STANDARD 14)

add_executable(TimurDZ main.cpp FileCommander.cpp FileCommander.h FileCommanderStream.cpp FileCommanderStream.h FileCommanderIterator.cpp FileCommanderIterator.h Modify.h)