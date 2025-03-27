cmake_minimum_required(VERSION 3.0.0)
project(paintbloatwave VERSION 0.1.0)

cmake_policy(SET CMP0072 NEW)

include_directories(src)


file(GLOB SOURCES "src/*.cpp" "src/Classes/*/*.cpp" "src/glad.h" "src/glad.c")
find_package(OpenGL REQUIRED)

add_executable(paintbloatwave ${SOURCES})

target_link_libraries(paintbloatwave 
    glfw
    OpenGL::GL
)
