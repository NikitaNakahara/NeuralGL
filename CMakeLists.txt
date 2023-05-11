cmake_minimum_required(VERSION 3.12)

set(LIB_NAME NGL)

project(${LIB_NAME}
    VERSION 1.0.0
    DESCRIPTION "Template for C++ library built with CMake"
    LANGUAGES CXX)

set(PUBLIC_HEADER
    include/NGL/ngl.hpp
)

set(SOURCES
    src/framebuffer.cpp
    src/framebuffer.hpp
)