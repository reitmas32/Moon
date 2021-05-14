## **ComponentSingleton_t**

Clase de la que heredan todos los compnentes *singleton*

Los Components son una de las partes mas importantes de la arquitectura ECS para videojuegos, con estos se dota de caracteristicas a las Entidades para que los sistemas puedan modificar el comportamiento de estas.

### Herencia
[ComponentBase_t](cmp_base.md)

### Definición
``` C++
/**
 * @file Moon/include/core/cmp/cmp.hpp
 */
template \<class Type>
struct ComponentSingleton_t : protected ComponentBase_t
```

| **Metodos públicos**                                  |
|:-----------------------------------------------------:|
| ComponentBase_t ()                                    |
| ~ComponentBase_t ()                                   |

| **Metodos públicos estaticos**                        |
|:-----------------------------------------------------:|
| static Moon::Alias::ComponentType getComponentType () |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

**Ejemplo**

``` C++
struct MediaQuery_t : Moon::Core::ComponentSingleton_t<MediaQuery_t>{
private:
     Size size;
     bool fullScreen;
public:
     MediaQuery_t(){}
 
     ~MediaQuery_t(){
         //TODO:All Destructor
     }
};

```

#### Contructores y Destructores

- **ComponentSingleton_t()**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    template<class Type>
    Moon::Core::ComponentSingleton_t<Type>::ComponentSingleton_t()
  ```

- **~ComponentSingleton_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    template<class Type >
    virtual Moon::Core::ComponentSingleton_t< Type >::~ComponentSingleton_t()
  ```

#### Funciones Miembro

- **getComponentType()**
  Obtiene el Tipo de Componente
  ``` C++
    /**
    * @pre None
    * @post The return is unique for each Component_t
    * @return Moon::Alias::ComponentType
    */
    template<class Type >
    static Moon::Alias::ComponentType Moon::Core::ComponentSingleton_t< Type >::getComponentType()
  ```