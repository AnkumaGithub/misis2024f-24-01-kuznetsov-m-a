set_property(GLOBAL PROPERTY CXX_STANDARD 11)

add_library(arrayd INTERFACE)
target_include_directories(arrayd INTERFACE arrayd.hpp)
