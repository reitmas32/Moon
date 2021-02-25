########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0)

if (CMAKE_VERSION VERSION_LESS 3.0)
  PROJECT(miniwin CXX)
else()
  cmake_policy(SET CMP0048 NEW)
  PROJECT(miniwin VERSION "1.0.0" LANGUAGES CXX)
endif()

########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
)

########################
#    Find Source of    #
#       Project        #
########################
file( GLOB_RECURSE LIB_SOURCES ${SOURCE_DIR}/*.cpp )
file( GLOB_RECURSE LIB_HEADERS ${INCLUDE_DIR}/*.hpp )

########################
#     Add Source of    #
#       Library        #
########################
add_library(
    miniwin
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)

########################
# Add Linker Libraries #
########################
TARGET_LINK_LIBRARIES( miniwin
    pthread
    X11
)

########################
#  Dir of the binary   #
########################
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR} CACHE PATH "Build directory" FORCE)
set(CMAKE_BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
