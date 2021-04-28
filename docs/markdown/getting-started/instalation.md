### Instalación
**Plataformas**
- Windows
- Linux
- MacOS(Próximamente)

Windows y Linux

Solo se requiere tener instalado CMake y algún Ninja junto a un compilador de C++ de su elección se recomienda g++ de cygwin para Windows y GNU GCC o Clang para Linux.
``` bash
mkdir MoonStudio
cd MoonStudio
git clone git@github.com:reitmas32/Moon.git
cd Moon
mkdir build
cd build
cmake .. -G <BuildSystem>-DCMAKE_CXX_COMPILER=<CXX_COMPILER> -DCMAKE_C_COMPILER=<C_COMPILER> -DCMAKE_CXX_FLAGS=”stdlib=libc++”
```