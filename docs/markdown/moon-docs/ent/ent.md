## **Entity_t**

Clase de la que heredan todas la entidades

Las Enidades son una parte esencial de la arquitectura ECS, en estas se almacenan un conjunto de Componentes de distintos tipos estos tiene relacion directa entre si los cuales dotan de caracteristicas a las entidades

### Herencia
[EntityBase_t](ent_base.md)

### Definición
``` C++
/**
 * @file Moon/include/core/ent/entity.hpp
 */
template <class Type>
struct Entity_t : public EntityBase_t
```

| **Metodos públicos**                                                           |
|:------------------------------------------------------------------------------:|
| Entity_t ()                                                                    |
| ~Entity_t ()                                                                   |
| Entity_t (Moon::Alias::EntityId eid)                                           |
| void updateComponent(Moon::Alias::ComponentType cid, ComponentBase_t *cmp_ptr) |
| auto begin()                                                                   |
| auto end()                                                                     |

| **Metodos públicos estaticos**                  |
|:-----------------------------------------------:|
| static Moon::Alias::EntityType getEntityType () |

| **Miembros heredados** |
|:----------------------:|
| MapCmps_t components   |

| **Miembros públicos**         |
|:-----------------------------:|
| Moon::Alias::EntityId eid = 0 |



### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

**Ejemplo**

``` C++
struct Pacman : Moon::Core::Entity_t<Pacman>{
public:
     Pacman(){}
 
     Pacman(Moon::Alias::EntityId eid) : Entity_t<Pacman>(eid){
         //TODO:All Constructor
     }
 
     ~Pacman(){
         //TODO:All Destructor
     }
};
```

#### Contructores y Destructores

- **Entity_t() [1/2]**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    template<class Type>
    Moon::Core::Entity_t<Type>::Entity_t()
  ```
- **Entity_t(Moon::Alias::EntityId 	eid	) [2/2]**<br>
  Constructor con inyeccion de Moon::Alias::EntityId<br>
  Definicion
  ``` C++
    template<class Type>
    Moon::Core::Entity_t<Type>::Entity_t(Moon::Alias::EntityId eid)
  ```

- **~Entity_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    template<class Type >
    virtual Moon::Core::Entity_t< Type >::~Entity_t()
  ```

#### Funciones Miembro

- **getComponentType()**
  Obtiene el Tipo de Componente
  ``` C++
    /**
    * @pre None
    * @post The return is unique for each Entity_t
    * @return Moon::Alias::EntityType
    */
    template<class Type >
    static Moon::Alias::EntityType Moon::Core::Entity_t< Type >::getEntityType()
  ```

- **updateComponent(Moon::Alias::ComponentType cid, ComponentBase_t \*cmp_ptr)**
  Actualiza la referenica a un Component_t
  ``` C++
    /**
    * @pre cmp_ptr not nullptr
    * @post The return is unique for each Entity_t
    * @return Moon::Alias::EntityType
    */
    template<class Type >
    void Moon::Core::Entity_t< Type >::updateComponent(Moon::Alias::ComponentType cid, ComponentBase_t *cmp_ptr)
  ```

- **begin()**
  Genera el mixin begin() para que Entity_t sea iterable
  ``` C++
    /**
    * @post The return is Map for Component_t
    * @return MapCmps_t
    */
    template<class Type >
    auto Moon::Core::Entity_t< Type >::begin()
  ```

- **end()**
  Genera el mixin end() para que Entity_t sea iterable
  ``` C++
    /**
    * @post The return is Map for Component_t
    * @return MapCmps_t
    */
    template<class Type >
    auto Moon::Core::Entity_t< Type >::end()
  ```