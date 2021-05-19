## **GameContext_t**

Las Enidades son una parte esencial de la arquitectura ECS, en estas se almacenan un conjunto de Componentes de distintos tipos estos tiene relacion directa entre si los cuales dotan de caracteristicas a las entidades

### Herencia
[GameContextBase_t](gtx_base.md)

### Definición
``` C++
/**
 * @file Moon/include/core/gtx/gtx.hpp
 */
template <typename Type>
struct GameContext_t : public GameContextBase_t
```

| **Metodos públicos**                                             |
|:----------------------------------------------------------------:|
| GameContext_t ()                                                 |
| ~GameContext_t ()                                                |
| ENT_t &addEntity(Ts &&...args)                                   |
| ENT_t *getEntityById(Moon::Alias::EntityId eid)                  |
| CMP_t &addComponentById(Moon::Alias::EntityId eid, Ts &&...args) |
| std::vector/<CMP_t> &getComponents()                             |
| std::vector/<ENT_t> &getEntities()                               |
| void destroyEntityById(Moon::Alias::EntityId eid)                |
| CMP_t *getRequiredComponent(Moon::Alias::EntityId eid)           |

| **Metodos públicos estaticos**                  |
|:-----------------------------------------------:|
| static Moon::Alias::GameContextType getGameContextType () |

| **Miembros públicos**         |
|:-----------------------------:|
| EntityStorage_t entities |
|ComponentStorage_t components|



### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

**Ejemplo**

``` C++
struct Gtx_t : Moon::Core::GameContext_t<Gtx_t>
{
    Gtx_t();
    ~Gtx_t();
};
 
//Use Gtx_t
 
//Create
auto gtx = Gtx_t();
 
//Add Entities
auto ent_1 = gtx.addEntity<Triangle_t>();
auto ent_2 = gtx.addEntity<Triangle_t>();
auto ent_3 = gtx.addEntity<Triangle_t>();
 
//Add Cmp to ent_1
gtx.addComponentById<Triangle_t, SpriteTriangle_t>(ent_1.eid, 0.2f);
gtx.addComponentById<Triangle_t, Position2Df_t>(ent_1.eid, 0.0f, 0.0f);
gtx.addComponentById<Triangle_t, PhysicsCmp_t>(ent_1.eid, true);
 
//Add Cmp to ent_2
gtx.addComponentById<Triangle_t, SpriteTriangle_t>(ent_2.eid, 0.15f);
gtx.addComponentById<Triangle_t, Position2Df_t>(ent_2.eid, 0.9f, -0.9f);
gtx.addComponentById<Triangle_t, IACmp_t>(ent_2.eid);
 
//Add Cmp to ent_3
gtx.addComponentById<Triangle_t, SpriteTriangle_t>(ent_3.eid, 0.1f);
gtx.addComponentById<Triangle_t, Position2Df_t>(ent_3.eid, -0.5f, -0.5f);
gtx.addComponentById<Triangle_t, RotateCmp_t>(ent_3.eid);
 
//Game Loop
 
while(...){
     .
     .
     .
     physicsSys.update(&gtx);
     renderSys.update(&gtx);
     inputSys.update();
     .
     .
     .
}
 
//In Updates of Systems
struct PhysicsSys_t : Moon::Core::System_t<Gtx_t>{
     void update(Gtx_t *gtx) override{
         for (Position2Df_t &cmp : gtx->getComponents<Position2Df_t>())
          {
              //Any Update cmp Physics
          }
     }
};
```

#### Contructores y Destructores

- **GameContext_t**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    template<typename Type>
    Moon::Core::GameContext_t<Type>::GameContext_t()
  ```

- **~GameContext_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    template<typename Type >
    virtual Moon::Core::GameContext_t< Type >::~GameContext_t()
  ```

#### Funciones Miembro

- **ENT_t &addEntity(Ts &&...args)**
    Añade una Entity
    ```C++
    /**
    * @tparam ENT_t Type of Entity
    * @param args params for the constructor of ENT_t
    * @return Type&
    */
    template <typename ENT_t, typename... Ts>
    ENT_t &Moon::Core::GameContext_t::addEntity(Ts &&...args)
    ```
- **ENT_t \*getEntityById(Moon::Alias::EntityId eid)**
    Regresa la Entity requerida
    ```C++
    /**
    * @tparam ENT_t Type of Entity
    * @param eid
    * @return ENT_t* reference to Entity
    */
    template <typename ENT_t>
    ENT_t *Moon::Core::GameContext_t::getEntityById(Moon::Alias::EntityId eid)
    ```

- **CMP_t &addComponentById(Moon::Alias::EntityId eid, Ts &&...args)**
    Añade un Component
    ```C++
    /**
    * @tparam ENT_t Type of Entity
    * @tparam CMP_t Type of Component
    * @param eid id of Entity
    * @param args params for constructor of Component
    * @return Cmp_t&
    */
    
    template <typename ENT_t, MOON_IS_CMP_T CMP_t, typename... Ts>
    CMP_t &Moon::Core::GameContext_t::addComponentById(Moon::Alias::EntityId eid, Ts &&...args)
    ```

- **std::vector<CMP_t> &getComponents()**
    Regresa los components
    ```C++
    /**
    * @tparam CMP_t Type of components
    * @return std::vector<CMP_t>&
    */
    template <MOON_IS_CMP_T CMP_t>
    std::vector<CMP_t> &Moon::Core::GameContext_t::getComponents()
    ```

- **std::vector<ENT_t> &getEntities()**
    Regresa los entities
    ```C++ 
    /**
    * @tparam ENT_t 
    * @return std::vector<ENT_t>&
    */
    template <typename ENT_t>
    std::vector<ENT_t> &Moon::Core::GameContext_t::getEntities()
    ```
- **void destroyEntityById(Moon::Alias::EntityId eid)**
    Delete la Entity seleccionada
    ```C++
    /**
    * @tparam ENT_t Type of Entity
    * @param eid if of Entity
    */
    template <typename ENT_t>
    void Moon::Core::GameContext_t::destroyEntityById(Moon::Alias::EntityId eid)
    ```

- **CMP_t \*getRequiredComponent(Moon::Alias::EntityId eid)**
    Regresa el Component requerido
    ```C++
    /**
    * @tparam CMP_t Type of Component
    * @param eid if of Entity
    */
    template <MOON_IS_CMP_T CMP_t>
    CMP_t *Moon::Core::GameContext_t::getRequiredComponent(Moon::Alias::EntityId eid)
    ```