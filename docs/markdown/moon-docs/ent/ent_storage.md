## EntityStorage_t

Clase Contenedora de EntityVect_t\<Type>

### Definición

```C++
/**
 * @file Moon/include/core/ent/ent_storage.hpp
 */
struct EntityStorage_t
```

| **Metodos públicos**                                                                          |
|:---------------------------------------------------------------------------------------------:|
| EntityStorage_t()                                                                          |
| ~EntityStorage_t()                                                                         |
| createEntity(Moon::Alias::EntityId eid, Ts &&...args)                                      |
| getEntities()                                                                               |
| getEntities() const                                                                         |
| deleteEntityByTypeIdAndEntityId(Moon::Alias::EntityType cid, Moon::Alias::EntityId eid) |

| **Metodos privados**    |
|:-----------------------:|
| createEntityVector() |

| **Miembros privados**                                                                        |
|:--------------------------------------------------------------------------------------------:|
| std::unordered_map<Moon::Alias::EntityType, std::unique_ptr<EntityBaseVect_t>> storage |

### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)


#### Contructores y Destructores

- **EntityStorage_t()**
    Constructo por defecto<br>
    Definición
    ``` C++
    struct Moon::Core::EntityStorage_t::EntityStorage_t()
    ```

- **~EntityStorage_t()**
    Destructor por defecto<br>
    Definición
    ``` C++
    struct Moon::Core::EntityStorage_t::~EntityStorage_t()
    ```

#### Funciones Miembro
- **createEntity(Moon::Alias::EntityId eid, Ts &&...args)**
    Crea un Entity_t y lo almacena en el Contenedor
    Definicion
    ```C++
    /**
    * @tparam ENT_t Type of new Entity_t
    * @param eid Id of the Entity to which the Entity belongs
    * @param Ts... Params of Contructor of Entity_t
    * @pre The Entity_t to create must have a constructor with the specified parameters
    * @return ENT_t& This is a reference to new Entity_t
    */
    template <MOON_IS_ENT_T ENT_t, typename... Ts>
    ENT_t &Moon::Core::EntityStorage_t::createEntity(Moon::Alias::EntityId eid, Ts &&...args)
    ```

- **getEntities()**
    Obtiene el vector del tipo de Entity_t solicitado
    Definicion
    ```C++
    /**
    * @tparam ENT_t Type of the Entity_t
    * @return std::vector<ENT_t>& Reference to vector of Entity_t's
    */
    template <MOON_IS_ENT_T ENT_t>
    std::vector<ENT_t> &Moon::Core::EntityStorage_t::getEntities()
    ```

- **getEntities() const**
    Obtiene el vector del tipo de Entity_t solicitado
    Definicion
    ```C++
    /**
    * @tparam ENT_t Type of the Entity_t
    * @return std::vector<ENT_t>& Reference to vector of Entity_t's
    */
    template <MOON_IS_ENT_T ENT_t>
    const std::vector<ENT_t> &Moon::Core::EntityStorage_t::getEntities() const
    ```

- **deleteEntityByTypeIdAndEntityId(Moon::Alias::EntityType cid, Moon::Alias::EntityId eid)**
    Elimina un Entity_t del tipo seleccionado y el eid 
    Definicion
    ```C++
    /**
    * @param cid Id of the Entity
    * @param eid Id of the Entity to which the Entity belongs
    * @return EntityBase_t* pointer of Entity_t Delete
    */
    EntityBase_t *
    deleteEntityByTypeIdAndEntityId(Moon::Alias::EntityType cid, Moon::Alias::EntityId eid)
    ```

#### Funciones Miembro privadas
- **createEntityVector()**
    Crea un std::vector\<ENT_t> del tipo indicado
    Definicion
    ```C++
    /**
    * @tparam ENT_t Type of the Entity_t
    * @return std::vector<ENT_t>& 
    */
    template <MOON_IS_ENT_T ENT_t>
    std::vector<ENT_t> &createEntityVector()
    ```