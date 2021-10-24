file(GLOB SOURCES
        *.h
        *.cpp
        core/*.h
        core/*.cpp
        components/*.h
        components/*.cpp
        )

find_package(SDL2 REQUIRED)

add_library(EngineT STATIC ${SOURCES})

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(EngineT ${SDL2_LIBRARY})

target_include_directories(EngineT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# install(TARGETS EngineT LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)