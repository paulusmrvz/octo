cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(octo C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_compile_definitions(NDEBUG)
endif()

add_subdirectory(vendor)
add_subdirectory(src)