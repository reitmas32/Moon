## **EntityBase_t**

Clase para crear CRTP de Component_t

### Definición
``` C++
/**
 * @file Moon/include/core/ent/ent_base.hpp
 */
struct EntityBase_t
```

| **Metodos públicos**     |
|:------------------------:|
| EntityBase_t()               |
| ~EntityBase_t()              |
| addComponent(CMP_t *cmp) |
| getComponent()           |

| **Miembros públicos estaticos**         |
|:---------------------------------------:|
| Moon::Alias::ComponentType nextType = 0 |

| **Miembros públicos**         |
|:-----------------------------:|
| MapCmps_t components          |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

### Contructores y Destructores

- **EntityBase_t()**<br>
  Constructor por defecto<br>
  Definicion
```C++
    Moon::Core::EntityBase_t::EntityBase_t()
```

- **~Entity_t()**<br>
  Destructor por defecto<br>
  Definicion
```C++
    Moon::Core::EntityBase_t::~EntityBase_t()
```

#### Funciones Miembro
- **addComponent(CMP_t \*cmp)**
    Añade una referencia al Component_t *cmp*
    Definicion
```C++
    /**
    * @tparam CMP_t Type of the Component_t
    * @pre CMP_t is base of Moon::Core::ComponentBase_t
    * @param cmp pointer of Component_t
    */
    template <MOON_IS_CMP_T CMP_t>
    void
    Moon::Core::Entity_t::addComponent(CMP_t *cmp)
```

- **getComponent()**
    Obtiene una referencia al Component_t *cmp*
    Definicion
```C++
    /**
    * @tparam CMP_t
    * @pre CMP_t is base of Moon::Core::ComponentBase_t
    * @return CMP_t*
    */
    template <MOON_IS_CMP_T CMP_t>
    CMP_t *Moon::Core::Entity_t::getComponent()
```