cmake_minimum_required(VERSION 3.17)
project(EngineT)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
file(GLOB SOURCES
        *.h
        *.cpp
        )

find_package(SDL2 REQUIRED)

add_executable(EngineT ${SOURCES})

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR}/core)
include_directories(${SDL2_INCLUDE_DIR}/components)
target_link_libraries(EngineT ${SDL2_LIBRARY})
