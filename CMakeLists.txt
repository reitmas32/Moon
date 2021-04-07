########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

set(NAME_PROJECT moon)

#########################
#   Name of Executable  #
#                       #
#########################
set(APP moon)

if (CMAKE_VERSION VERSION_LESS 3.0)
    PROJECT(${NAME_PROJECT} CXX)
else()
    cmake_policy(SET CMP0048 NEW)
    PROJECT(${NAME_PROJECT} VERSION "1.0.0" LANGUAGES CXX)
endif()

PROJECT(${APP} CXX)
if(${WIN32})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/windows.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/windows.cmake)
    endif()
elseif(${UNIX})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/linux.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/linux.cmake)
    endif()
endif()