include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(split SHARED split.cpp)
add_library(mytype SHARED mytype.cpp)


add_executable(split_cpp split.cpp)
add_executable(mytype_cpp mytype.cpp)
