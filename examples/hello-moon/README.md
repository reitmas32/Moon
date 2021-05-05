# hello-Moon example

Este es un proyecto basico usando solo el **Core** de **Moon**

Para compilar este ejemplo necesitas
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
    - Ejemplo Windows 

        ```bash
        cd Moon
        mkdir build
        cmake -G "Ninja" .. -DCMAKE_CXX_COMPILER=clang++
        ninja
        ```
### Compilar este proyecto
- Ejemplo Linux 

    ```bash
    cd Moon/examples/hello-moon
    mkdir build
    cmake .. -DCMAKE_CXX_COMPILER=g++-10
    make
    ```
- Ejemplo Windows 

    ```bash
    cd Moon/examples/hello-moon
    mkdir build
    cmake -G "Ninja" .. -DCMAKE_CXX_COMPILER=clang++
    ninja
    ```