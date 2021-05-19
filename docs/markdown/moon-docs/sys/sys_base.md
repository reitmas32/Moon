## **SystemBase_t**

Clase para crear CRTP de System_t

### Definición
``` C++
/**
 * @file Moon/include/core/sys/sys_base.hpp
 */
struct SystemBase_t
```

| **Metodos públicos** |
|:--------------------:|
| SystemBase_t ()      |
| ~SystemBase_t ()     |

| **Metodos públicos virtuales** |
|:------------------------------:|
| virtual bool alive()           |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

#### Contructores y Destructores

- **SystemBase_t()**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    Moon::Core::SystemBase_t()
  ```

- **~SystemBase_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    virtual Moon::Core::~SystemBase_t()
  ```

#### Funciones Miembro

- **bool alive() = 0**
    Indica si el System_t esta activo
    ```C++
    bool alive() = 0
    ```