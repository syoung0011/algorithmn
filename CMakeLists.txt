cmake_minimum_required(VERSION 3.16)
project(algorithmn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Common utility headers (linked list / binary tree definitions)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Collect all solution sources under topic directories (0x-topic_name),
# each source file is compiled into a standalone executable, target name = file name (without extension)
file(GLOB_RECURSE SOLUTION_SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/[0-9]*/*.cpp")

foreach(SRC ${SOLUTION_SOURCES})
    get_filename_component(SOL_NAME ${SRC} NAME_WE)
    add_executable(${SOL_NAME} ${SRC})
    # All executables are placed under the bin/ directory of the build tree
    set_target_properties(${SOL_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endforeach()

list(LENGTH SOLUTION_SOURCES SOLUTION_COUNT)
message(STATUS "algorithmn: found ${SOLUTION_COUNT} solution file(s)")
