cmake_minimum_required(VERSION 3.30)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)


project(CppLearn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
find_package(Eigen3 REQUIRED)
find_package(GTest REQUIRED)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.hpp")

add_executable(CppLearn main.cpp ${SOURCES})

target_link_libraries(CppLearn PRIVATE Eigen3::Eigen)

if(EXISTS ${TEST_DIR})
    enable_testing()

    file(GLOB_RECURSE TEST_SOURCES "${TEST_DIR}/*.cpp")

    add_executable(run_tests ${TEST_SOURCES} ${SOURCES})

    target_link_libraries(run_tests PRIVATE Eigen3::Eigen GTest::gtest GTest::gtest_main)

    add_test(NAME CppLearnTests COMMAND run_tests)
endif()