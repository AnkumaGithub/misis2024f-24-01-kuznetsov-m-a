add_executable(complex_test complex_test.cpp)
add_executable(complex_doctest complex_doctest.cpp)

add_executable(rational_test rational_test.cpp)
add_executable(rational_doctest rational_doctest.cpp)

add_executable(arrayd_test arrayd_test.cpp)
add_executable(arrayd_doctest arrayd_doctest.cpp)

add_executable(arrayt_doctest arrayt_doctest.cpp)
add_executable(arrayt_test arrayt_test.cpp)

add_executable(queuea_test queuea_test.cpp)

add_executable(stackl_test stackl_test.cpp)

add_executable(stacka_test stacka_test.cpp)



target_link_libraries(complex_test complex)
target_link_libraries(complex_doctest complex)

target_link_libraries(rational_test rational)
target_link_libraries(rational_doctest rational)

target_link_libraries(arrayd_test arrayd)
target_link_libraries(arrayd_doctest arrayd)

target_link_libraries(arrayt_test arrayt)
target_link_libraries(arrayt_doctest arrayt)

target_link_libraries(queuea_test queuea)

target_link_libraries(stackl_test stackl)

target_link_libraries(stacka_test stacka)

