cmake_minimum_required(VERSION 3.10)

project(algorithm_cplusplus VERSION 0.1.0)

find_package(GTest REQUIRED)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_library(
    algorithm
    SHARED
    src/calc_max_profit.cpp
    src/sort.cpp
    src/search.cpp
)

target_include_directories(algorithm
    PUBLIC 
    "include"
)

include(CPack)
