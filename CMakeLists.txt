########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

project (main VERSION 1.2.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INCLUDE_DIR_MOON ${CMAKE_CURRENT_SOURCE_DIR}/lib/moon/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
    ${INCLUDE_DIR_MOON}
)

########################
#    Find Source of    #
#       Project        #
########################
file( GLOB_RECURSE LIB_SOURCES ${SOURCE_DIR}/*.cpp )
file( GLOB_RECURSE LIB_HEADERS ${INCLUDE_DIR}/*.hpp )
file( GLOB_RECURSE LIB_HEADERS_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/*/include/*.hpp )

########################
#     Add Source of    #
#       Project        #
########################
add_executable(
    app 
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
    ${LIB_HEADERS_LIB}
)
#target_link_libraries( app
#pthread
#)
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
    set(CMAKE_BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/build)
endif()
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")  
#cmake -DBUILD_SHARED_LIBS=ON
#make
#sudo cp -a googletest/include/gtest /usr/include
#sudo cp lib/libgtest_main.so lib/libgtest.so /usr/lib/

#sudo pacman -Syu gtest
#sudo apt-get install libgtest-dev