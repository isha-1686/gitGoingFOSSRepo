cmake_minimum_required(VERSION 3.16)
project(cpp_cli_calc_plus LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTING "Enable tests" ON)

add_library(calclib
    src/calculator.cpp
    src/logging.cpp
    src/config.cpp
)
target_include_directories(calclib PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(calc_app src/app/main.cpp)
target_link_libraries(calc_app calclib)

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()