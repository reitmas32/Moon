########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

set(NAME_PROJECT __name_project__)

set(APP __name_build__)

if (CMAKE_VERSION VERSION_LESS 3.0)
    PROJECT(${NAME_PROJECT} CXX)
else()
    cmake_policy(SET CMP0048 NEW)
    PROJECT(${NAME_PROJECT} VERSION "1.0.0" LANGUAGES CXX)
endif()

if(${WIN32})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/windows.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/windows.cmake)
    endif()
elseif(${UNIX})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/linux.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/linux.cmake)
    endif()
endif()