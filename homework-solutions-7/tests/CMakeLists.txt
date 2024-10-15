# /tests/CMakeLists.txt
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)



# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)
# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)


add_executable(test_split test_split.cpp) # Compile a test source
add_executable(test_mytype test_mytype.cpp) # Compile a test source
add_executable(test_sum test_sum.cpp) # Compile a test source
add_executable(test_pair test_pair.cpp) # Compile a test source
add_executable(test_transform test_transform.cpp) # Compile a test source
add_executable(test_is_raw_pointer test_is_raw_pointer.cpp) # Compile a test source
add_executable(test_flexible_container test_flexible_container.cpp) # Compile a test source


# Link against any required libraries. The library "some_library" is compiled in src/
target_link_libraries(test_split split) # Compile a test source
target_link_libraries(test_mytype mytype) # Compile a test source


gtest_discover_tests(test_split)
gtest_discover_tests(test_mytype)
gtest_discover_tests(test_sum)
gtest_discover_tests(test_pair)
gtest_discover_tests(test_transform)
gtest_discover_tests(test_is_raw_pointer)
gtest_discover_tests(test_flexible_container)
