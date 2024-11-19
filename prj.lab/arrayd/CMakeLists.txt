set_property(GLOBAL PROPERTY CXX_STANDARD 11)

add_library(arrayd_l INTERFACE)
target_include_directories(arrayd_l INTERFACE arrayd.hpp)
