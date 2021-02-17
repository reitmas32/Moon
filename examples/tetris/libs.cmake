########################
#       MINIWIN        #
########################
#  Options for include #
#  the library Miniwin #
#                      #
########################
option(MINIWIN_LIB "")

#   Compilig with Source Code
if(${MINIWIN_LIB} STREQUAL "SOURCE")

    add_subdirectory(lib/miniwin)
    target_link_libraries(${APP} PRIVATE miniwin)

#   Alone Linker Lib
elseif(${MINIWIN_LIB} STREQUAL "BINARY")

    target_link_libraries(${APP} ${CMAKE_CURRENT_SOURCE_DIR}/lib/miniwin/build/cmake/libminiwin.so)

else()
#   Default Linker Library
    add_subdirectory(lib/miniwin)
    target_link_libraries(${APP} PRIVATE miniwin)
    message("Default Linker Library")

endif()

add_subdirectory(lib/Moon)
target_link_libraries(${APP} PRIVATE moon ncurses)