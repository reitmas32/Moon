########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

if (CMAKE_VERSION VERSION_LESS 3.0)
  PROJECT(tetris CXX)
else()
  cmake_policy(SET CMP0048 NEW)
  PROJECT(tetris VERSION "1.0.0" LANGUAGES CXX)
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(APP Tetris )

########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/cmake)

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
#       Project        #
########################
add_executable(
    ${APP} 
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)
########################
#     Include Libs     #
########################
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
endif()

########################
#       Testing        #
########################

if( test AND test STREQUAL "on" )

  message("Testing enabled")

    ########################
    #     Test_SOURCE      #
    ########################
    file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
    set(TESTING_SOURCE ${LIB_SOURCES} )
    list(REMOVE_ITEM TESTING_SOURCE ${SOURCE_DIR}/main.cpp)

    ########################
    #     Init_Testing     #
    ########################
    enable_testing()
    add_executable(runUnitTests ${TEST_SRC_FILES} ${TESTING_SOURCE} )

    ########################
    #  Library of Testing  #
    ########################
    target_link_libraries(runUnitTests gtest gtest_main)

    ########################
    #   Build of Testing   #
    ######################## 
    add_test(UnitTests runUnitTests)
else()

    ########################
    #  Dir of the binary   #
    ########################
    set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR} CACHE PATH "Build directory" FORCE)
    set(CMAKE_BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/build/cmake)
endif()

set(CMAKE_CXX_COMPILER "/usr/bin/clang++") 