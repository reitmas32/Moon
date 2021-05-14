## ComponentStorage_t

Clase Contenedora de ComponentVect_t\<Type>

### Definición

```C++
/**
 * @file Moon/include/core/cmp/cmp_storage.hpp
 */
struct ComponentStorage_t
```

| **Metodos públicos**                                                                          |
|:---------------------------------------------------------------------------------------------:|
| ComponentStorage_t()                                                                          |
| ~ComponentStorage_t()                                                                         |
| createComponent(Moon::Alias::EntityId eid, Ts &&...args)                                      |
| getComponents()                                                                               |
| getComponents() const                                                                         |
| deleteComponentByTypeIdAndEntityId(Moon::Alias::ComponentType cid, Moon::Alias::EntityId eid) |

| **Metodos privados**    |
|:-----------------------:|
| createComponentVector() |

| **Miembros privados**                                                                        |
|:--------------------------------------------------------------------------------------------:|
| std::unordered_map<Moon::Alias::ComponentType, std::unique_ptr<ComponentBaseVect_t>> storage |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)


#### Contructores y Destructores

- **ComponentStorage_t()**
    Constructo por defecto<br>
    Definición
    ``` C++
    struct Moon::Core::ComponentStorage_t::ComponentStorage_t()
    ```

- **~ComponentStorage_t()**
    Destructor por defecto<br>
    Definición
    ``` C++
    struct Moon::Core::ComponentStorage_t::~ComponentStorage_t()
    ```

#### Funciones Miembro
- **createComponent(Moon::Alias::EntityId eid, Ts &&...args)**
    Crea un Component_t y lo almacena en el Contenedor
    Definicion
    ```C++
    /**
    * @tparam CMP_t Type of new Component_t
    * @param eid Id of the Entity to which the Component belongs
    * @param Ts... Params of Contructor of Component_t
    * @pre The Component_t to create must have a constructor with the specified parameters
    * @return CMP_t& This is a reference to new Component_t
    */
    template <MOON_IS_CMP_T CMP_t, typename... Ts>
    CMP_t &Moon::Core::ComponentStorage_t::createComponent(Moon::Alias::EntityId eid, Ts &&...args)
    ```

- **getComponents()**
    Obtiene el vector del tipo de Component_t solicitado
    Definicion
    ```C++
    /**
    * @tparam CMP_t Type of the Component_t
    * @return std::vector<CMP_t>& Reference to vector of Component_t's
    */
    template <MOON_IS_CMP_T CMP_t>
    std::vector<CMP_t> &Moon::Core::ComponentStorage_t::getComponents()
    ```

- **getComponents() const**
    Obtiene el vector del tipo de Component_t solicitado
    Definicion
    ```C++
    /**
    * @tparam CMP_t Type of the Component_t
    * @return std::vector<CMP_t>& Reference to vector of Component_t's
    */
    template <MOON_IS_CMP_T CMP_t>
    const std::vector<CMP_t> &Moon::Core::ComponentStorage_t::getComponents() const
    ```

- **deleteComponentByTypeIdAndEntityId(Moon::Alias::ComponentType cid, Moon::Alias::EntityId eid)**
    Elimina un Component_t del tipo seleccionado y el eid 
    Definicion
    ```C++
    /**
    * @param cid Id of the Component
    * @param eid Id of the Entity to which the Component belongs
    * @return ComponentBase_t* pointer of Component_t Delete
    */
    ComponentBase_t *
    deleteComponentByTypeIdAndEntityId(Moon::Alias::ComponentType cid, Moon::Alias::EntityId eid)
    ```

#### Funciones Miembro privadas
- **createComponentVector()**
    Crea un std::vector\<CMP_t> del tipo indicado
    Definicion
    ```C++
    /**
    * @tparam CMP_t Type of the Component_t
    * @return std::vector<CMP_t>& 
    */
    template <MOON_IS_CMP_T CMP_t>
    std::vector<CMP_t> &createComponentVector()
    ```