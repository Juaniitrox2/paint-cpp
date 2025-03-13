cmake_minimum_required(VERSION 3.0.0)
project(paintdih VERSION 0.1.0)

cmake_policy(SET CMP0072 NEW)

include_directories(src)

find_package(OpenGL REQUIRED)

add_executable(paintdih 
    src/main.cpp 
    src/glad.h 
    src/glad.c
)

target_link_libraries(paintdih 
    glfw
    OpenGL::GL
)
