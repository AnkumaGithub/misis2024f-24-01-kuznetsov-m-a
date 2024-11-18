set_property(GLOBAL PROPERTY CXX_STANDARD 11)

add_library(marray_l INTERFACE)
target_include_directories(marray_l INTERFACE marray.hpp)
