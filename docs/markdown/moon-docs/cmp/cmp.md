## **Component_t**

Clase de la que heredan todos los compnentes 

Los Components son una de las partes mas importantes de la arquitectura ECS para videojuegos, con estos se dota de caracteristicas a las Entidades para que los sistemas puedan modificar el comportamiento de estas.

### Herencia
[ComponentBase_t](cmp_base.md)

### Definición
``` C++
/**
 * @file Moon/include/core/cmp/cmp.hpp
 */
template \<class Type>
struct Component_t : public ComponentBase_t
```

| **Metodos públicos**                        |
|:-------------------------------------------:|
| Component_t ()                              |
| ~Component_t ()                             |
| Component_t (Moon::Alias::EntityId eid)     |

| **Metodos públicos estaticos**                        |
|:-----------------------------------------------------:|
| static Moon::Alias::ComponentType getComponentType	() |

| **Miembros heredados**    |
|:-------------------------:|
| Moon::Alias::EntityId eid |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

**Ejemplo**

``` C++
struct Sprite_t : Moon::Core::Component_t<Sprite_t>{
private:
     std::vector<Image> sprite;
public:
     Sprite_t(){}
 
     Sprite_t(Moon::Alias::EntityId eid) : Component_t<Sprite_t>(eid){
         //TODO:All Constructor
     }
 
     ~Sprite_t(){
         //TODO:All Destructor
     }
};

```

#### Contructores y Destructores

- **Component_t() [1/2]**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    template<class Type>
    Moon::Core::Component_t<Type>::Component_t()
  ```
- **Component_t(Moon::Alias::EntityId 	eid	) [2/2]**<br>
  Constructor con inyeccion de Moon::Alias::EntityId<br>
  Definicion
  ``` C++
    template<class Type>
    Moon::Core::Component_t<Type>::Component_t(Moon::Alias::EntityId eid)
  ```

- **~Component_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    template<class Type >
    virtual Moon::Core::Component_t< Type >::~Component_t()
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
    static Moon::Alias::ComponentType Moon::Core::Component_t< Type >::getComponentType()
  ```