cmake_minimum_required(VERSION 3.7)

project(yna)

option(YNA_BUILD_EXAMPLES "Build the YNA example programs" ON)
option(YNA_BUILD_TESTS "Build the YNA test programs" ON)

add_subdirectory(src)

if (YNA_BUILD_EXAMPLES)
    add_subdirectory(example)
endif (YNA_BUILD_EXAMPLES)

if (YNA_BUILD_TESTS)
    add_subdirectory(tests)
endif (YNA_BUILD_TESTS)
