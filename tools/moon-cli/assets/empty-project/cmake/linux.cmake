#   cmake/linux.cmake

########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

#Add Dependencies
include(cmake/vendor.cmake)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
    #Includes of Mooon
    ${MOON_INCLUDE_DIR}
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
#TODO: add_library
add_executable(
    ${APP} 
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)
target_link_libraries(${APP}
    ${MOON_LIBRARIES}
    )