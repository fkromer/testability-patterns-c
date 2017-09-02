# Copyright (C) 2017 Florian Kromer - MIT

cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
set(includes_production ${PROJECT_SOURCE_DIR}/inc)
set(includes_test ${PROJECT_SOURCE_DIR}/src)
include_directories(${GTEST_INCLUDE_DIRS} ${includes_production} ${includes_test})

file(GLOB_RECURSE sources_production src/*.c)
file(GLOB_RECURSE sources_test test/*.cc)

add_definitions(-DTEST)  # enable compile time test hooks
add_executable(unit_tests ${sources_test} ${sources_production})
target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread)
