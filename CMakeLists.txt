set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
cmake_minimum_required(VERSION 3.17)
project(EngineJ)

file(GLOB LIB_SOURCES
        lib/*.h
        lib/*.cpp
        lib/core/*.h
        lib/core/*.cpp
        lib/components/*.h
        lib/components/*.cpp
        lib/systems/*.h
        lib/systems/*.cpp
        lib/types/*.h
        lib/types/*.cpp
        )
find_package(SDL2 REQUIRED)
add_executable(EngineJ ${LIB_SOURCES})
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(EngineJ ${SDL2_LIBRARY})