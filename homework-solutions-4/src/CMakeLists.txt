include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(student_class SHARED student_class.cpp)
add_library(dynamic_array SHARED dynamic_array.cpp)


# add_library(person SHARED person.h)
# add_library(dyn_array SHARED dyn_array.h)

# set_target_properties(person PROPERTIES LINKER_LANGUAGE CXX) # need to specify C++ as a linker language
# set_target_properties(dyn_array PROPERTIES LINKER_LANGUAGE CXX) # need to specify C++ as a linker language

add_executable(person_cpp person.cpp)
add_executable(dynamic_array_cpp dynamic_array.cpp)
add_executable(student_class_cpp student_class.cpp)

# add_library(student_class_lib SHARED student_class.cpp)

# target_link_libraries(student_class student_class_lib)
# target_link_libraries(person)
# target_link_libraries(dyn_array)
