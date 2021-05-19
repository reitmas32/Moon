## **System_t**

La manipulación de los datos de un vídeo juego es una tarea compleja de administrar cuando uno esta iniciando en el desarrollo de vídeo juegos, podrías terminar con un acoplamiento entre las partes que lo componen a tal punto en el que el modulo encargado de la física también manipule datos de renderizado. Por esta razón es importante tener una buena planificación.
La arquitectura ECS "Entity Component System" es una forma sencilla y eficiente de administrar los recursos de un vídeo juego, como su nombre lo indica esta se basa en separa los Datos "Entity Component" de la manipulación e interpretación de los mismos "System"

### Herencia
[SystemBase_t](gtx_base.md)

### Definición
``` C++
/**
 * @file Moon/include/core/sys/sys.hpp
 */
template <MOON_IS_CTX_T... Type>
struct System_t : public SystemBase_t
```

| **Metodos públicos**                                             |
|:----------------------------------------------------------------:|
| System_t ()                                                 |
| ~System_t ()                                                |
|virtual void update(Type *...gameContext)|
|virtual bool alive()|

| **Metodos públicos estaticos**                  |
|:-----------------------------------------------:|
| static Moon::Alias::SystemType getSystemType () |

| **Miembros públicos**         |
|:-----------------------------:|
| EntityStorage_t entities |
|ComponentStorage_t components|



### **Descripcion detallada**

**Estabilidad**

![KEGE Studios](https://raw.githubusercontent.com/reitmas32/Moon/master/assets/stability/stability_2.png)

**Ejemplo**

``` C++
struct PhysicsSys_t : Moon::Core::System_t<Gtx_t>
{
    inline static Moon::Tools::TimeStep_t time = Moon::Tools::TimeStep_t();
    void update(Gtx_t *gtx) override;
 
    bool alive() override;
};
 
//Use
 
//Create
auto physicsSys = PhysicsSys_t();
 
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
 
//Update Method
     void update(Gtx_t *gtx) override{
         for (Position2Df_t &cmp : gtx->getComponents<Position2Df_t>())
          {
              //Any Update cmp Physics
          }
     }
```

#### Contructores y Destructores

- **System_t**<br>
  Constructor por defecto<br>
  Definicion
  ``` C++
    template <MOON_IS_CTX_T... Type>
    Moon::Core::System_t<Type>::System_t()
  ```

- **~System_t()**<br>
  Destructor por defecto<br>
  Definicion
  ``` C++
    template <MOON_IS_CTX_T... Type>
    virtual Moon::Core::System_t< Type >::~System_t()
  ```

#### Funciones Miembro

- **void update(Type *...gameContext)**
    Actualiza el estado del GameContext_t recibido
    ```C++
    /**
    * @param gameContext
    */
    template <MOON_IS_CTX_T... Type>
    virtual void &Moon::Core::System_t::update(Type *...gameContext)
    ```
- **bool alive() = 0**
    Indica si el System_t esta activo
    ```C++
    template <MOON_IS_CTX_T... Type>
    bool alive() = 0
    ```