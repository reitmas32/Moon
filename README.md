# Moon

<center><img src="https://raw.githubusercontent.com/reitmas32/Moon/master/assets/logo-moon.png"></center>

Moon es un Game Engine desarrollado por [KEGE Studios](https://github.com/EGE-Studios) escrito en C/C++,  fue diseñado basado en la Arquitectura [ECS](http://entity-systems.wikidot.com/) y usando algunas funcionalidades del nuevo estandar de [C++20](https://en.cppreference.com/w/cpp/20)

### **Características principales**

- Eficiente en el uso de Recursos
- Arquitectura Kernel para el escalamiento e interacción entre los plugins
- Uso de la STL para los contenedores
- Concepts implementados para una mayor seguridad en templates
- Predicción de tipos en tiempo de compilación
- Un Core simple, liviano y libre
- Plugins pequeños y específicos
- Ejemplos para todos los plugins oficiales
- Solo incluyes lo que necesitas
- Independencia de plugins

### **Características de la versión**

- GameContext
- System
- Component
- Entity
- Herramienta de Instalacion y creacion de proyectos
- Uso de la STL para los contenedores
- Predicción de tipos en tiempo de compilación

## **Configuración del entorno**

Añade la variable de entorno

```bash
MOON_STUDIO_PATH=$HOME/MoonStudio
```

Esto servirá para la creación de los proyectos de Moon

## **Instalación**

### Plataformas 
- Windows
- Linux
- MacOS(Proximamente)

Windows y Linux

Solo se requiere tener instalado CMake y algún BuildSystem como Ninja para WIndows y Unix Makefile para Linux junto a un compilador de C++ de su elección se recomienda g++ de cygwin para Windows y GNU GCC o Clang para Linux.

```bash
# Creamos la carpeta donde se instalaran tanto el core como los plugins
mkdir MoonStudio
cd MoonStudio

# Clonamos el repositorio de Moon
git clone git@github.com:reitmas32/Moon.git
cd Moon

# Creamos una carpeta para los .lib .a y ejecutables
mkdir build
cd build

# Creamos la configuracion de Cmake para la compilacion de Moon
cmake .. -G <BuildSystem>-DCMAKE_CXX_COMPILER=<CXX_COMPILER> -DCMAKE_C_COMPILER=<C_COMPILER> -DCMAKE_CXX_FLAGS=”stdlib=libc++”

# Por ultimo dependiendo del BuildSystem que usemos compilaremos el proyecto 
```


### Usando Moon Core
- Puede en contrar ejemplos de Moon en los siguientes repositorios
    - [Examples](https://github.com/EGE-Studios/Moon/tree/master/examples)

## **Contribución en Moon**

¡Gracias por invertir su tiempo en contribuir a nuestro proyecto! Cualquier contribución que haga se reflejará en https://github.com/reitmas32/Moon.

Lea nuestro [Código de conducta](https://github.com/reitmas32/Moon/blob/master/CODE_OF_CONDUCT.md) para mantener nuestra comunidad accesible y respetable.

### Formato para la contribucion de Commits

- feat(feature-name): mensage del commit
- fix(feature-name): mensage del commit
- docs(feature-name): mensage del commit
- breaking(feature-name): mensage del commit

### Plugins
- [Moon Terminal](https://github.com/reitmas32/Moon_Terminal)

## **Docuemntación**

Para obtener mayor informacin sobre **Moon** puede consultar nuestra [Documentación](https://ambiguous-sweater-c99.notion.site/Moon-Engine-dd64f15918ca4c63b8c129dae2991d79)