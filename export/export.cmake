if(${WIN32})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/windows.cmake)
        ##include(${CMAKE_CURRENT_SOURCE_DIR}/windows.cmake)
    endif()
elseif(${UNIX})
    if(EXISTS $ENV{HOME}/opt/MoonStudio/Moon/export/linux.cmake)
        include($ENV{HOME}/opt/MoonStudio/Moon/export/linux.cmake)
    endif()
endif()

#solo se de be incluir asiinclude($ENV{HOME}/opt/MoonStudio/Moon/export/export.cmake)