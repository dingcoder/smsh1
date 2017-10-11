cmake_minimum_required(VERSION 3.8)
project(smsh1)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c smsh.h execute.c)
add_executable(smsh1 ${SOURCE_FILES})