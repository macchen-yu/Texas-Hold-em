cmake_minimum_required(VERSION 3.28)
project(Tex_poker C)

set(CMAKE_C_STANDARD 23)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/Inc)

# Collect all source files in the Src directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/Src/*.c")

# Add the executable
add_executable(Tex_poker main.c ${SOURCES})
