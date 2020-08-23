cmake_minimum_required (VERSION 3.5)

project (debt_o_meter)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/")
set (BUILD "${PROJECT_SOURCE_DIR}/build/")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES})
include_directories(${Qt5Charts_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(${Qt5Charts_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}" "${Qt5Charts_EXECUTABLE_COMPILE_FLAGS}")

file (GLOB SOURCE_FILES "${SOURCE_DIR}/*.cxx")

add_executable (debt_o_meter ${SOURCE_FILES})

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
target_link_libraries(debt_o_meter ${Qt5Widgets_LIBRARIES} ${Qt5Charts_LIBRARIES})