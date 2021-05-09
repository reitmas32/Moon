# cmake/moon.cmake

#########################
#       Lib Moon        #
#########################
if(${WIN32})
    
    add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/Moon)
    
    set(MOON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/vendor/Moon/include ${CMAKE_SOURCE_DIR}/vendor/Moon/template ${CMAKE_SOURCE_DIR}/vendor/Moon/vendor/termcolor)
    set(MOON_LIBRARIES ${MOON_LIBRARIES} moon)
    
    option(LOGS "ON")
    if(${LOGS} STREQUAL "OFF")
    add_compile_definitions(RELEASE)
    endif()

elseif(${UNIX})
    #   Dir of MoonStudio
    set(MOON_STUDIO_DIR $ENV{HOME}/MoonStudio)

    set(MOON_INCLUDE_DIR 
        ${MOON_STUDIO_DIR} 
        ${MOON_STUDIO_DIR}/Moon/template 
        ${MOON_STUDIO_DIR}/Moon/include 
        ${MOON_STUDIO_DIR}/Moon/vendor/termcolor)

    message(${MOON_INCLUDE_DIR})
    option(LOGS "ON")
    if(${LOGS} STREQUAL "OFF")
        #add_compile_definitions(RELEASE)
        set(MOON_LIBRARIES ${MOON_STUDIO_DIR}/Moon/build/libmoon.a)
    else()
        set(MOON_LIBRARIES ${MOON_STUDIO_DIR}/Moon/build/libmoon.a)
    endif()

endif()