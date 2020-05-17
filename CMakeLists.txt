# CMakeLists for fomatest
#
# Copyright 2018 by Damir Cavar
#


cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)
project(fomaJNI)
set(EXECUTABLE_NAME "fomaJNI")

# add all .cpp and .h files to source
file(GLOB ALL_MY_SRC
    "*.h"
    "*.cpp")

include_directories(/usr/local/include)
include_directories($ENV{JAVA_HOME}/include)
include_directories($ENV{JAVA_HOME}/include/darwin) # exchange 'darwin' by your operating system
link_directories(/usr/local/lib)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

find_library(FomaLib NAMES libfoma.a)
find_library(ZLib NAMES z)

add_library(${EXECUTABLE_NAME} SHARED ${ALL_MY_SRC})
target_link_libraries(${EXECUTABLE_NAME} ${FomaLib} ${ZLib})

