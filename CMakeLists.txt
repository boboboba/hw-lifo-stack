cmake_minimum_required(VERSION 3.10)
project(HideSecret CXX)

option(WITH_TESTS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
if (CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
      ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_library(stack stack.cpp)

if (WITH_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)

  add_executable(unit-test test.cpp stack.cpp)
  target_link_libraries(unit-test PRIVATE GTest::gtest_main)
  include(GoogleTest)

  gtest_discover_tests(unit-test)
  target_compile_options(unit-test PRIVATE -fsanitize=address,undefined)
  target_link_options(unit-test PRIVATE -fsanitize=address,undefined)
endif ()
