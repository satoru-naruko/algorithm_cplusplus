cmake_minimum_required(VERSION 3.0.0)
project(algorithm_cplusplus VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(algorithm_cplusplus  
    main.cpp 
    src/calc_max_profit.cpp
    src/insertion_sort.cpp
)

target_include_directories(algorithm_cplusplus
    PUBLIC 
    "include"
)

include(CPack)
