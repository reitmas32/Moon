# cmake/moon.cmake

#########################
#       Lib Moon        #
#########################
if(${WIN32})
    
    #   Dir of MoonStudio
    set(MOON_STUDIO_DIR $ENV{MOON_STUDIO_DIR})

    set(MOON_INCLUDE_DIR 
        ${MOON_STUDIO_DIR} 
        ${MOON_STUDIO_DIR}/Moon/template 
        ${MOON_STUDIO_DIR}/Moon/include 
        ${MOON_STUDIO_DIR}/Moon/vendor/termcolor)

    message(${MOON_INCLUDE_DIR})
    option(LOGS "ON")
    if(${LOGS} STREQUAL "OFF")
        #add_compile_definitions(RELEASE)
        set(MOON_LIBRARIES ${MOON_STUDIO_DIR}/Moon/build/moon.lib)
    else()
        set(MOON_LIBRARIES ${MOON_STUDIO_DIR}/Moon/build/moon.lib)
    endif()

elseif(${UNIX})
    #   Dir of MoonStudio
    set(MOON_STUDIO_DIR $ENV{MOON_STUDIO_DIR})

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