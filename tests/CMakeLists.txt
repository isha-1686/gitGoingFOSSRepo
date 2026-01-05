add_executable(calc_tests
    tests_calculator.cpp
)
target_link_libraries(calc_tests PRIVATE calclib)
add_test(NAME calc_tests COMMAND calc_tests)
