########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0)

if (CMAKE_VERSION VERSION_LESS 3.0)
  PROJECT(moon CXX)
else()
  cmake_policy(SET CMP0048 NEW)
  PROJECT(moon VERSION "1.0.0" LANGUAGES CXX)
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
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
    moon
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)

########################
# Add Linker Libraries #
########################
TARGET_LINK_LIBRARIES( moon
    pthread
    X11
)

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
    #set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR} CACHE PATH "Build directory" FORCE)
    #set(CMAKE_BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/build)
endif()

########################
#     Examples of      #
#       Project        #
########################
option(EXAMPLES "OFF")

if(${EXAMPLES} STREQUAL "ON")

  message("GENERATE THE EXAMPLES")

  set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)
  file( GLOB_RECURSE LIB_EXAMPLES ${EXAMPLES_DIR}/*.cpp )

  foreach(var IN LISTS LIB_EXAMPLES)
    string(REGEX REPLACE "[A-Za-z/]*/examples/" "" IN_EXECUTABLE ${var})
    string(REGEX REPLACE ".cpp" "" OUT_EXECUTABLE ${IN_EXECUTABLE})
    add_executable(${OUT_EXECUTABLE} ${var})
    target_link_libraries(${OUT_EXECUTABLE} PUBLIC moon ncurses)

    add_custom_command(
      TARGET ${OUT_EXECUTABLE} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
              ${CMAKE_CURRENT_SOURCE_DIR}/build/cmake/${OUT_EXECUTABLE}
              ${CMAKE_CURRENT_SOURCE_DIR}/build/cmake/examples/${OUT_EXECUTABLE}
      COMMAND ${CMAKE_COMMAND} -E remove -f
              ${CMAKE_CURRENT_SOURCE_DIR}/build/cmake/${OUT_EXECUTABLE})


  endforeach()

endif()
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
