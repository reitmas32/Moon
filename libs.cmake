########################
#       CALC_2         #
########################
#  Options for include #
#  the library         #
#                      #
########################
option(MOON_LIB "")

#   Compilig with Source Code
if(${MOON_LIB} STREQUAL "SOURCE")

    add_subdirectory(lib/moon)
    target_link_libraries(app PUBLIC moon)

#   Alone Linker Lib
elseif(${MOON_LIB} STREQUAL "BINARY")

    target_link_libraries(app ${CMAKE_CURRENT_SOURCE_DIR}/lib/moon/build/cmake/libmoon.so)

else()
#   Default Linker Library
    add_subdirectory(lib/moon)
    target_link_libraries(app PUBLIC moon ncurses)
    message("Default Linker Library")

endif()