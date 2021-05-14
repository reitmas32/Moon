## **ComponentBase_t**

Clase para crear CRTP de Component_t

### Definición
``` C++
/**
 * @file Moon/include/core/cmp/ccmp_base.hpp
 */
struct ComponentBase_t
```

| **Metodos públicos** |
|:--------------------:|
| ComponentBase_t()    |
| ~ComponentBase_t()   |

| **Miembros públicos estaticos**         |
|:---------------------------------------:|
| Moon::Alias::ComponentType nextType = 0 |

| **Miembros públicos**         |
|:-----------------------------:|
| Moon::Alias::EntityId eid = 0 |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

### Contructores y Destructores

- **ComponentBase_t()**<br>
  Constructor por defecto<br>
  Definicion
```C++
    Moon::Core::ComponentBase_t::ComponentBase_t()
```

- **~ComponentBase_t()**<br>
  Destructor por defecto<br>
  Definicion
```C++
    Moon::Core::ComponentBase_t::~ComponentBase_t()
```