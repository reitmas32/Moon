## **GameContextBase_t**

Clase para crear CRTP de GameContext_t

Cuando realizamos un vídeo juego debemos encontrar la manera de almacenar los datos de las entidades de tal forma que los sistemas que modifican éstos datos puedan acceder a ellos de la forma mas rápida posible.

### Definición
``` C++
/**
 * @file Moon/include/core/gtx/gtx_base.hpp
 */
struct GameContextBase_t
```

| **Metodos públicos**                       |
|:------------------------------------------:|
| GameContextBase_t ()                       |
| ~GameContextBase_t ()                      |

| **Miembros publicos estaticos**            |
| :-------------------------:                |
| Moon::Alias::EntityId nextId{ 0 }          |
| Moon::Alias::GameContextType nextType{ 0 } |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

#### Contructores y Destructores

- **GameContextBase_t()**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    Moon::Core::GameContextBase_t()
  ```

- **~GameContextBase_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    virtual Moon::Core::~GameContextBase_t()
  ```