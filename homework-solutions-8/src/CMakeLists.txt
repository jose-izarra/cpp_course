include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(zipfs_containers SHARED main_zipfs_containers.cpp)
add_library(zipfs_algorithms SHARED main_zipfs_algorithms.cpp)

add_executable(main_zipfs_containers main_zipfs_containers.cpp)
add_executable(main_zipfs_algorithms main_zipfs_algorithms.cpp)
