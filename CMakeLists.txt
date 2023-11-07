cmake_minimum_required(VERSION 3.10)

project(algorithm_cplusplus VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
add_library(
    algorithm
    SHARED
    src/calc_max_profit.cpp
    src/sort.cpp
    src/search.cpp
)
target_include_directories(algorithm PUBLIC include)

include(CTest)

# Google TestのCMake設定
include(ExternalProject)
ExternalProject_Add(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)
ExternalProject_Get_Property(googletest source_dir binary_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include)
set(GTEST_LIBS_DIR ${binary_dir})
find_package(GTest REQUIRED)


# テストターゲットの設定
add_executable(algorithm_tests
    test/main.cpp
    test/test_search.cpp
)
target_include_directories(algorithm_tests PRIVATE include ${GTEST_INCLUDE_DIRS})
target_link_libraries(algorithm_tests algorithm GTest::GTest GTest::Main)

# テスト実行ターゲットの設定
enable_testing()
add_test(NAME algorithm_tests COMMAND algorithm_tests)
