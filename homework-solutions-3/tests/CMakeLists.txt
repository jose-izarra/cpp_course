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

add_executable(test_student test_student.cpp)

target_include_directories(test_student PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(
    test_student
    GTest::gtest_main
)

gtest_discover_tests(test_student)
