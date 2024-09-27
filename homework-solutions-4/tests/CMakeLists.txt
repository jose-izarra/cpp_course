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

add_executable(test_student test_student.cpp) # Compile a test source
add_executable(test_dynamic_array test_dynamic_array.cpp)
# Link against any required libraries. The library "some_library" is compiled in src/
target_link_libraries(test_student student_class)
target_link_libraries(test_dynamic_array dynamic_array)
gtest_discover_tests(test_student test_dynamic_array)            # Register the tests to gtest
