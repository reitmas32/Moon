# Moon Core

Moon es un Game Engine desarrollado por [KEGE Studios](https://github.com/EGE-Studios) escrito en C/C++,  fue diseñado basado en la Arquitectura [ECS](http://entity-systems.wikidot.com/) y usando algunas funcionalidades del nuevo estandar de [C++20](https://en.cppreference.com/w/cpp/20)

![KEGE Studios](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/KegeStudios.png)

### Plataformas 
- Windows
- Linux
- MacOS(Proximamente)

### Sistema de Compilación
- Para la comilación se usa [CMake](https://cmake.org/)

### Instalación y Compilación
- ##### Windows
    - Solo se requiere tener instalado **CMake** y algun **Build System** ( Como Visual Studio o CodeBlock ) junto a algun compilador de C++ de su elección
    - Clone el repositorio actual
    - Ejecute los comando(recomendado)
    ```
    mkdir build/cmake
    cmake ../..
    ```
    - Esto generara un proyecto del Build System que elegio

- ##### Linux
    - Solo se requiere tener instalado **CMake** y **Make** junto a algun compilador de C++ de su elección
    - Clone el repositorio actual
    - Ejecute los comando(recomendado)
    ```
    mkdir -p build/cmake
    cmake ../..
    make
    ```

### Usando Moon Core
- Puede en contrar ejemplos de Moon en los siguientes repositorios
    - [Examples](https://github.com/EGE-Studios/Moon/tree/master/examples)

## Documentación de Moon Core

#### Tipos
- EntityId: ID para identificar a cada una de las entidades del juego
- ##### Tipos utilizados para identificar a cada una de las clases heredadas del Game Engine
    - EntityType
    - SystemType
    - ComponentType
    - GameContextType
#### Clases
- ComponentBase_t

![ComponentBase_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/ComponentBase_t.png)

- Component_t

![Component_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/Component_t.png)

- EntityBase_t

![EntityBase_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/EntittyBase_t.png)

- Entity_t

![Entity_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/Entity_t.png)

- SystemBase_t

![SystemBase_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/SystemBase_t.png)

- System_t

![System_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/System_t.png)

- GameContextBase_t

![GameContextBase_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/GameContextBase_t.png)

- GameContext_t

![GameContext_t](https://raw.githubusercontent.com/EGE-Studios/Moon/master/assets/GameContext_t.png)
