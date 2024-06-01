cmake_minimum_required(VERSION 3.10)

project(SimpleNuklearApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/solver.cpp
    stc/equation.cpp
)

add_executable(calc ${SOURCES})