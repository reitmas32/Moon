# Moon

<center><img src="https://raw.githubusercontent.com/reitmas32/Moon/master/assets/logo-moon.png"></center>

Moon es un Game Engine desarrollado por [KEGE Studios](https://github.com/EGE-Studios) escrito en C/C++,  fue diseñado basado en la Arquitectura [ECS](http://entity-systems.wikidot.com/) y usando algunas funcionalidades del nuevo estandar de [C++20](https://en.cppreference.com/w/cpp/20)

![KEGE Studios](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/KegeStudios.png)

### Plataformas 
- Windows
- Linux
- MacOS(Proximamente)

#### Requisitos
- Un compilador de C++, recomendado [gcc](https://gcc.gnu.org/) usar la version 10 preferentemente, [clang](https://clang.llvm.org/) y [cygwin](https://www.cygwin.com/)
- Un build system para compilar el proyecto [Make](https://www.gnu.org/software/make/) para Linux y [Ninja](https://ninja-build.org/) para Windows y Linux
- [CMake](https://cmake.org/)

### Instalación y Compilación
Para compilar este proyecto necesitas
- requerimentos basicos de Moon
- Crear una varible de entorno MOON_STUDIO_DIR que tendra el valor del directorio en el que se encuentra MoonStudio
- Compilar Moon
    - Ejemplo Linux 

        ```bash
        cd Moon
        mkdir build
        cmake .. -DCMAKE_CXX_COMPILER=g++-10
        make
        ```
        - Añade a la variable PATH Moon/tools/moon-cli/dist-linux/bin
    - Ejemplo Windows 

        ```bash
        cd Moon
        mkdir build
        cmake -G "Ninja" .. -DCMAKE_CXX_COMPILER=clang++
        ninja
        ```
        - Añade a la variable PATH Moon/tools/moon-cli/dist-windows/bin

### Compilando UTest de Moon Core

- Clonar el repositorio con `--recursive` o actualizar `git submodule update --init`
- `cd test/googletest`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`
- `cd ../../..`
- Compilar el proyecto nuevamente con `-Dtest=on` en cmake

### Usando Moon Core
- Puede en contrar ejemplos de Moon en los siguientes repositorios
    - [Examples](https://github.com/EGE-Studios/Moon/tree/master/examples)

### Formato para la contribucion de Commits

- feat(feature-name): mensage del commit
- fix(feature-name): mensage del commit
- docs(feature-name): mensage del commit
- breaking(feature-name): mensage del commit

### Plugins
- [Moon Terminal](git@github.com:reitmas32/Moon_Terminal.git)