### Hola Mundo

Primero necesitamos crear el directorio de nuestro proyecto
``` bash
mkdir hello-world
cd hello-world
```

Ahora crearemos algunas carpetas para organizar el proyecto
```
mkdir src/ include/ cmake/
```

Para la compilacion de nuestro proyecto aligual que hicimos con Moon usaremos [CMake](https://cmake.org/), los siguientes archivos serviran para la configuración
``` cmake
# CMakeLists.txt

########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

set(NAME_PROJECT HelloMoon)

set(APP hello-moon)

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
```
``` cmake
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
```
``` cmake
#   cmake/windows.cmake

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
```

``` cmake
#   cmake/vendor.cmake

########################
#     Include Moon     #
########################
include(cmake/moon.cmake)
```

``` cmake

# cmake/moon.cmake

#########################
#       Lib Moon        #
#########################
if(${WIN32})
    #   Dir of MoonStudio
    set(MOON_STUDIO_DIR $ENV{MOON_STUDIO_PATH})

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

elseif(${UNIX})
    #   Dir of MoonStudio
    set(MOON_STUDIO_DIR $ENV{MOON_STUDIO_PATH})

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
```

Despues de esta configuaración creamos un archivo main.cpp y creamos nuestro primer component

``` C++
//  src/main.cpp

#include <iostream>

//Info Platform
#include <Moon/include/tools/platform_info.hpp>

//Component
#include <Moon/template/core/cmp/cmp.tpp>

//MyComponent
struct MyCmp_t : Moon::Core::Component_t<MyCmp_t>
{
    //data of Component
    int data;

    //Constructors
    MyCmp_t(Moon::Alias::EntityId eid) : Moon::Core::Component_t<MyCmp_t>(eid) {}
    MyCmp_t(
        Moon::Alias::EntityId eid,
        int data) : Moon::Core::Component_t<MyCmp_t>(eid), data{data}{}
    MyCmp_t() = default;

    //Destructors
    ~MyCmp_t() = default;   
};

int main(int argc, char const *argv[])
{
    MyCmp_t cmp = MyCmp_t(0, 45); // eid = 0, data = 45
    std::cout << "MyCmp_t eid: "<<cmp.eid<<", data: " << cmp.data << std::endl;
    return 0;
}
```