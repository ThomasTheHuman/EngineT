file(GLOB SOURCES *.c)
find_package(PythonExtensions REQUIRED)

add_library(_pyenginet MODULE ${SOURCES})
target_link_libraries(_pyenginet EngineT)
python_extension_module(_pyenginet)
install(TARGETS _pyenginet LIBRARY DESTINATION pyenginet)

#set_target_properties(
#    enginet
#    PROPERTIES
#        PREFIX ""
#        OUTPUT_NAME "enginet"
#        LINKER_LANGUAGE C
#)

# target_link_libraries(py ${PYTHON_LIBRARY} ${ENGINE_T})
# include_directories(${PYTHON_INCLUDE_DIR} ../libEngineT)
# find_library(ENGINE_T EngineT lib)
# install(TARGETS PyEngineT LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)