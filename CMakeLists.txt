cmake_minimum_required(VERSION 3.5)

project(nvim-cmake-plugin-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
  GIT_PROGRESS TRUE)

if(NOT googletest_POPULATED)
  message("populating googletest")
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

enable_testing()

add_executable(${PROJECT_NAME}
    test.cpp
)

target_link_libraries(${PROJECT_NAME} gtest gmock gtest_main)

add_test(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/bin/cpp-basics-tests)
