include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(expression SHARED expression.cpp)
add_executable(expression_cpp expression.cpp)
