cmake_minimum_required(VERSION 3.27)
project(yekta)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(yekta
        main.cpp
        user.cpp
        user.h
        new.cpp
        new.h)
