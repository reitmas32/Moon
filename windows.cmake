########################
#     Use Threads      #
########################
option(CMAKE_USE_WIN32_THREADS_INIT "using WIN32 threads" ON)

########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEMPLATE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/template)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test/googletest/googletest/include)

########################
# Google Test Include  #
########################
#set(INCLUDE_TEST_DIR C:/Users/$ENV{USERNAME}/opt/Moon/test/googletest/googletest/include)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
    ${TEMPLATE_DIR}
    ${TEST_INCLUDE_DIR}
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
add_library(
    moon 
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)

########################
#     Link Libs        #
########################
target_link_libraries(${APP} ${LIBS_PROYECT})

########################
#     Include Libs     #
########################
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
    #include(${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
endif()

########################
#     Config from      #
#     Build System     #
########################
if(${CMAKE_GENERATOR} STREQUAL "Ninja")
    #Todo:Ninja
endif()

if(${CMAKE_GENERATOR} STREQUAL "Visual Studio 16 2019")
    #Todo: Visual Studio
endif()

if(${CMAKE_GENERATOR} STREQUAL "NMake Makefiles")
  #Todo:NMaka
endif()

if(${CMAKE_GENERATOR} STREQUAL "MinGW Makefiles")
    #Todo:MinGW Makefile
endif()

########################
#  Use C++20 Standar   #
########################
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
target_compile_features(moon PUBLIC cxx_std_20)
#
#################################
## GTest
#################################
if( test AND test STREQUAL "on" )

    set(TEST_EXE runUnitTests)

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
    add_executable(${TEST_EXE} ${TEST_SRC_FILES} ${TESTING_SOURCE} )

    ########################
    #  Library of Testing  #
    ########################
    target_link_libraries(${TEST_EXE} ${CMAKE_CURRENT_SOURCE_DIR}/test/googletest/build/Release/lib/gtestd.lib ${CMAKE_CURRENT_SOURCE_DIR}/test/googletest/build/Release/lib/gtest_maind.lib)
    
    ########################
    #   Build of Testing   #
    ######################## 
    add_test( ${TEST_EXE} ${TEST_EXE} )
    target_compile_features(${TEST_EXE} PUBLIC cxx_std_20)
endif()