set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
cmake_minimum_required(VERSION 3.17)
project(pyenginet)


# libEngineT.a
file(GLOB LIB_SOURCES
        lib/*.h
        lib/*.cpp
        lib/core/*.h
        lib/core/*.cpp
        lib/components/*.h
        lib/components/*.cpp
        lib/api/*.h
        lib/api/*.cpp
        )
find_package(SDL2 REQUIRED)
add_library(EngineT STATIC ${LIB_SOURCES})
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(EngineT ${SDL2_LIBRARY})
target_include_directories(EngineT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# _pyenginet.so
file(GLOB PY_SOURCES pyenginet/*.c)
find_package(PythonExtensions REQUIRED)
add_library(_pyenginet MODULE ${PY_SOURCES})
target_link_libraries(_pyenginet EngineT)
python_extension_module(_pyenginet)
install(TARGETS _pyenginet LIBRARY DESTINATION pyenginet)