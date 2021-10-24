set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
cmake_minimum_required(VERSION 3.17)
project(pyenginet)

add_subdirectory(EngineT)
add_subdirectory(pyenginet)