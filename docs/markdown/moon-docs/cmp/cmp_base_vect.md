## **ComponentBaseVect_t**

Abstracción de un ComponentVect_t

### Definición

```C++
/**
 * @file Moon/include/core/cmp/cmp_vect.hpp
 */
struct ComponentBaseVect_t
```

| **Metodos públicos**                                 |
|:----------------------------------------------------:|
| ComponentBaseVect_t()                                |
| ~ComponentBaseVect_t()                               |
| deleteComponentByEntityId(Moon::Alias::EntityId eid) |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

#### Contructores y Destructores

- **ComponentBaseVect_t()**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    Moon::Core::ComponentBaseVect_t::ComponentBaseVect_t()
  ```

- **~ComponentBaseVect_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    virtual Moon::Core::ComponentBaseVect_t::~ComponentBaseVect_t()
  ```

#### Funciones Miembro
- **deleteComponentByEntityId(Moon::Alias::EntityId eid)**
    Elimina un Component_t usando eid
    ``` C++
    /**
    * @param eid Id of the Entity to which the Component belongs
    * @return ComponentBase_t* pointer of Component_t Delete
    */
    virtual Moon::Core::ComponentBase_t *Moon::Core::ComponentBaseVect_t::deleteComponentByEntityId(Moon::Alias::EntityId eid) = 0
    ```