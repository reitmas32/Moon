# Moon Core

Moon es un Game Engine desarrollado por [KEGE Studios](https://github.com/EGE-Studios) escrito en C/C++,  fue diseñado basado en la Arquitectura [ECS](http://entity-systems.wikidot.com/) y usando algunas funcionalidades del nuevo estandar de [C++20](https://en.cppreference.com/w/cpp/20)

![KEGE Studios](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/KegeStudios.png)

### Plataformas 
- Windows
- Linux
- MacOS(Proximamente)

#### Requisitos
- Un compilador de C++, recomendado [gcc](https://gcc.gnu.org/) o [clang](https://clang.llvm.org/)
- [Make](https://www.gnu.org/software/make/) para Linux y [Ninja](https://ninja-build.org/) para Windows
- [CMake](https://cmake.org/)

### Instalación y Compilación
- ##### Windows
    - Solo se requiere tener instalado **CMake** y algun **Ninja** junto a algun compilador de C++ de su elección se recomienda g++ de **cygwin**
    - Clone el repositorio actual
    - Ejecute los comando(recomendado)
        - **Release**
          - `mkdir build/Release`
          - `cd build/Release`
          - `cmake ../.. -G "Ninja" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE=-O3 -DCMAKE_C_FLAGS_RELEASE=-O3 -DLOGS=OFF`
          - `ninja`

        - **Debug**
          - `mkdir build/Debug`
          - `cd build/Debug`
          - `cmake ../.. -G "Ninja" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_DEBUG=-g -DCMAKE_C_FLAGS_DEBUG=-g -DLOGS=ON`
          - `ninja`
      - Esto generara un proyecto del Build System que elegio

- ##### Linux
    - Solo se requiere tener instalado **CMake** y **Make** junto a algun compilador de C++ de su elección
    - Clone el repositorio actual
    - Ejecute los comando(recomendado)
        - **Release** 
          - `mkdir build/Release`
          - `cd build/Release`
          - `cmake ../.. -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE=-O3 -DCMAKE_C_FLAGS_RELEASE=-O3 -DLOGS=OFF`
          - `make`

        - **Debug**
          - `mkdir build/Debug`  
          - `cd build/Debug`
          - `cmake ../.. -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_DEBUG=-g -DCMAKE_C_FLAGS_DEBUG=-g -DLOGS=ON`
          - `make`

### Usando Moon Core
- Puede en contrar ejemplos de Moon en los siguientes repositorios
    - [Examples](https://github.com/EGE-Studios/Moon/tree/master/examples)
