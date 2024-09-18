add_library(doubly_linked_list SHARED doubly_linked_list.h)
set_target_properties(doubly_linked_list PROPERTIES LINKER_LANGUAGE CXX) # need to specify C++ as a linker language
target_link_libraries(doubly_linked_list)
