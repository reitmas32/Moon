## **EntityVect_t**

Wrapper de un vector de Entity_t\<Type> 

### Herencia
[EntityBaseVect_t](cmp_base_vect.md)

### Definición

```C++
/**
 * @file Moon/include/core/ent/ent_vect.hpp
 */
template <MOON_IS_ENT_T ENT_t>
struct EntityVect_t : EntityBaseVect_t
```

| **Metodos públicos**                                 |
|:----------------------------------------------------:|
| EntityVect_t()                                    |
| ~EntityVect_t()                                   |
| findEntityIteratorById(Moon::Alias::EntityId eid) |
| deleteEntityByEntityId(Moon::Alias::EntityId eid) |

| **Metodos públicos heredados**                       |
|:----------------------------------------------------:|
| deleteEntityByEntityId(Moon::Alias::EntityId eid) |

| **Miembros públicos**                                  |
|:------------------------------------------------------:|
| Moon::Alias::EntityId eid |
|std::vector<ENT_t> entities |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

#### Contructores y Destructores

- **EntityVect_t()**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    template<MOON_IS_ENT_T ENT_t>
    Moon::Core::EntityVect_t<ENT_t>::EntityVect_t()
  ```

- **~EntityVect_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    template<MOON_IS_ENT_T ENT_t>
    virtual Moon::Core::EntityVect_t< ENT_t >::~EntityVect_t()
  ```

#### Funciones Miembro

- **findEntityIteratorById(Moon::Alias::EntityId eid)**
  Busca un Entity utilizando *eid*
  ``` C++
    /**
    * @param eid Id of the Entity to which the Entity belongs
    * @return Entity_t* with Id equal eid
    */
    template<MOON_IS_ENT_T ENT_t>
    constexpr auto Moon::Core::EntityVect_t< ENT_t >::findEntityIteratorById(Moon::Alias::EntityId eid) noexcept
  ```

- **deleteEntityByEntityId(Moon::Alias::EntityId eid)**
  ELimina un Entity utilizando *eid*
  ``` C++
    /**
    * @param eid Id of the Entity to which the Entity belongs
    * @return EntityBase_t* pointer of Entity_t Delete
    */
    template<MOON_IS_ENT_T ENT_t>
    Moon::Core::EntityBase_t *Moon::Core::EntityVect_t< ENT_t >::deleteEntityByEntityId(Moon::Alias::EntityId eid) override final
  ```

