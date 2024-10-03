
# /CMakeLists.txt
# Every CMake project needs to start with these two lines
cmake_minimum_required(VERSION 3.28) # This is the minimum version of CMake required
project(Homework VERSION 1.0) # This is the name of the project and its version
set(PROJECT_AUTHOR "Jose Izarra") # This is the author of the project

set(CMAKE_CXX_STANDARD 20) # This sets the C++ standard to C++20
set(CMAKE_CXX_STANDARD_REQUIRED True) # This tells CMake that the stdandard must be available
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=arm64")
# This line tells CMake to generate the compile_commands.json file, which VSCode can use to provide intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# We place the executables in the bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# We place the libraries in the lib directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)



# Doxygen setup
find_package(Doxygen REQUIRED)
if (DOXYGEN_FOUND)
    # Configure Doxyfile
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # Add custom target for Doxygen
    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
endif()


# We normally have a CMakeLists.txt file in each directory that has something that needs to be built
add_subdirectory(src)
enable_testing() # This line allows to call ctest after compilation
add_subdirectory(tests)
# add_subdirectory(docs)
