cmake_minimum_required (VERSION 3.5)

project (debt_o_meter)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/")
set (BUILD "${PROJECT_SOURCE_DIR}/build/")

file (GLOB SOURCE_FILES "${SOURCE_DIR}/*.cxx")

add_executable (debt_o_meter ${SOURCE_FILES})
