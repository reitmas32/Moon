## **EntityBaseVect_t**

Abstracción de un EntityVect_t

### Definición

```C++
/**
 * @file Moon/include/core/ent/ent_vect.hpp
 */
struct EntityBaseVect_t
```

| **Metodos públicos**                                 |
|:----------------------------------------------------:|
| EntityBaseVect_t()                                |
| ~EntityBaseVect_t()                               |
| deleteEntityByEntityId(Moon::Alias::EntityId eid) |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

#### Contructores y Destructores

- **EntityBaseVect_t()**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    Moon::Core::EntityBaseVect_t::EntityBaseVect_t()
  ```

- **~EntityBaseVect_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    virtual Moon::Core::EntityBaseVect_t::~EntityBaseVect_t()
  ```

#### Funciones Miembro
- **deleteEntityByEntityId(Moon::Alias::EntityId eid)**
    Elimina un Entity_t usando eid
    ``` C++
    /**
    * @param eid Id of the Entity to which the Entity belongs
    * @return EntityBase_t* pointer of Entity_t Delete
    */
    virtual Moon::Core::EntityBase_t *Moon::Core::EntityBaseVect_t::deleteEntityByEntityId(Moon::Alias::EntityId eid) = 0
    ```