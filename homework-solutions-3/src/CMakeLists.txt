add_executable(student_class_cpp student_class.cpp)

# add_library(student_class_lib SHARED student_class.cpp)
add_library(student_class SHARED student_class.h)
set_target_properties(student_class PROPERTIES LINKER_LANGUAGE CXX) # need to specify C++ as a linker language

# target_link_libraries(student_class student_class_lib)
target_link_libraries(student_class)
