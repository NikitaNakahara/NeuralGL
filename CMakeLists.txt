cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME ngl)

set(SRC
    src/Window.cpp
    src/Window.hpp
)
set(INCLUDE include/NeuralGL/ngl.hpp)

project(ngl)

add_library(${PROJECT_NAME} STATIC ${SRC} ${INCLUDE})
add_library(Nakaharadev::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

if(UNIX)
    message("-- Link libs for unix")
    target_link_libraries(${PROJECT_NAME} X11)
    
    if(BUILD_OPENGL)
        target_link_libraries(${PROJECT_NAME} GL)
    endif()
endif(UNIX)