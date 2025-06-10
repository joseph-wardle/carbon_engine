cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/CPM.cmake)
# CPMAddPackage(gh:fmtlib/fmt#11.1.4)


project(carbon_engine LANGUAGES CXX)
option(CARBON_TEST "Build tests" OFF)

add_subdirectory(src)

if(CARBON_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()