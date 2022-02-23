cmake_minimum_required(VERSION 3.0.0)
project(algorithm_cplusplus VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(algorithm_cplusplus main.cpp calc_max_profit.cpp)

set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
