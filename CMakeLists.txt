#    Created by Jakub Nowak 2023.
cmake_minimum_required(VERSION 3.0.0)
project(GTest_Template VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

# Create executable
add_executable(GTest_Template 
    src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
