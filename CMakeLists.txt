cmake_minimum_required(VERSION 3.21)
project(clouds_counter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_library(clouds_counter Sky.h Sky.cpp)

add_executable(clouds_counter_tests test.cpp)
target_link_libraries(clouds_counter_tests gtest clouds_counter)