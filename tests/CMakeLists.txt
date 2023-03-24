#    Created by Jakub Nowak 2023.

cmake_minimum_required(VERSION 3.0.0)
project(GTest_Template_Tests VERSION 0.1.0)

# Include googleTests from github
include(FetchContent)
set (CMAKE_CXX_STANDARD 17)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# Create executable
add_executable(test_module tests.cc)

# Link googleTest library
target_link_libraries(test_module
 PRIVATE
  GTest::GTest
  )
# Include directrories with code to test
include_directories(
    ${CMAKE_SOURCE_DIR}/../inc)
link_directories(
    ${CMAKE_SOURCE_DIR}/../inc)

# Add tests
add_test(NAME hello_gtests COMMAND test_module "${CMAKE_CURRENT_LIST_DIR}")
# Add CTest support for VScode running
include(CTest)
enable_testing()