## **ComponentVect_t**

Wrapper de un vector de Component_t\<Type> 

### Herencia
[ComponentBaseVect_t](cmp_base_vect.md)

### Definición

```C++
/**
 * @file Moon/include/core/cmp/cmp_vect.hpp
 */
template <MOON_IS_CMP_T CMP_t>
struct ComponentVect_t : ComponentBaseVect_t
```

| **Metodos públicos**                                 |
|:----------------------------------------------------:|
| ComponentVect_t()                                    |
| ~ComponentVect_t()                                   |
| findComponentIteratorById(Moon::Alias::EntityId eid) |
| deleteComponentByEntityId(Moon::Alias::EntityId eid) |

| **Metodos públicos heredados**                       |
|:----------------------------------------------------:|
| deleteComponentByEntityId(Moon::Alias::EntityId eid) |

| **Miembros públicos**                                  |
|:------------------------------------------------------:|
| Moon::Alias::EntityId eidstd::vector<CMP_t> components |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

#### Contructores y Destructores

- **ComponentVect_t()**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    template<MOON_IS_CMP_T CMP_t>
    Moon::Core::ComponentVect_t<CMP_t>::ComponentVect_t()
  ```

- **~ComponentVect_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    template<MOON_IS_CMP_T CMP_t >
    virtual Moon::Core::ComponentVect_t< CMP_t >::~ComponentVect_t()
  ```

#### Funciones Miembro

- **findComponentIteratorById(Moon::Alias::EntityId eid)**
  Busca un Componente utilizando *eid*
  ``` C++
    /**
    * @param eid Id of the Entity to which the Component belongs
    * @return Component_t* with Id equal eid
    */
    template<MOON_IS_CMP_T CMP_t >
    constexpr auto Moon::Core::ComponentVect_t< CMP_t >::findComponentIteratorById(Moon::Alias::EntityId eid) noexcept
  ```

- **deleteComponentByEntityId(Moon::Alias::EntityId eid)**
  Elimina un Componente utilizando *eid*
  ``` C++
    /**
    * @param eid Id of the Entity to which the Component belongs
    * @return ComponentBase_t* pointer of Component_t Delete
    */
    template<MOON_IS_CMP_T CMP_t >
    Moon::Core::ComponentBase_t *Moon::Core::ComponentVect_t< CMP_t >::deleteComponentByEntityId(Moon::Alias::EntityId eid) override final
  ```

