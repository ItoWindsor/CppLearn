cmake_minimum_required(VERSION 3.30)

project(CppLearn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Conan toolchain
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Find dependencies
find_package(Eigen3 REQUIRED)
find_package(GTest REQUIRED)

# Set up directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)

# Include directories
include_directories(${INCLUDE_DIR})

# Gather source and header files
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.hpp")

# Add executable
add_executable(CppLearn main.cpp ${SOURCES})

# Link dependencies
target_link_libraries(CppLearn PRIVATE Eigen3::Eigen ${CONAN_LIBS})

# Set up tests
if(EXISTS ${TEST_DIR})
    enable_testing()
    file(GLOB_RECURSE TEST_SOURCES "${TEST_DIR}/*.cpp")
    add_executable(run_tests ${TEST_SOURCES} ${SOURCES})
    target_include_directories(run_tests PRIVATE ${INCLUDE_DIR})
    target_link_libraries(run_tests PRIVATE Eigen3::Eigen GTest::gtest GTest::gtest_main ${CONAN_LIBS})
    add_test(NAME CppLearnTests COMMAND run_tests)
endif()
