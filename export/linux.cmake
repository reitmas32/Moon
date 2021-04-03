
########################
#     Moon Include     #
########################
set(MOON_INCLUDE_DIR $ENV{HOME}/opt/MoonStudio $ENV{HOME}/opt/MoonStudio/Moon/template $ENV{HOME}/opt/MoonStudio/Moon/include $ENV{HOME}/opt/MoonStudio/Moon/vendor/spdlog/include)

#########################
#       Lib Moon        #
#########################
set(MOON_LIBRARIES $ENV{HOME}/opt/MoonStudio/Moon/build/Release/libmoon.a)

option(LOGS "ON")
if(${LOGS} STREQUAL "OFF")
    add_compile_definitions(RELEASE)
else()
    set(MOON_LIBRARIES ${MOON_LIBRARIES} $ENV{HOME}/opt/MoonStudio/Moon/vendor/spdlog/build/libspdlog.a)
endif()