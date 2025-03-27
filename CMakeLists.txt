cmake_minimum_required(VERSION 3.30)
project(CppLearn)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
find_package(Eigen3 REQUIRED)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.hpp")

add_executable(CppLearn main.cpp ${SOURCES})

target_link_libraries(CppLearn PRIVATE Eigen3::Eigen)