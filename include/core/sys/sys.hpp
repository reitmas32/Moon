/**
 * @file system.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que heredan los Systems del Motor
 * @version 1.2.0
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// Alias
#include <core/alias.hpp>

// SystemBase
#include <core/sys/sys_base.hpp>

#include <core/concepts.hpp>

/**
 * @include moon_log.hpp
 */
#include <tools/moon_log.hpp>

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core
{
     /**
     * @subsubsection Example
     * @code{.cpp}
     * struct PhysicsSys_t : Moon::Core::System_t<Gtx_t>
     * {
     *     inline static Moon::Tools::TimeStep_t time = Moon::Tools::TimeStep_t();
     *     void update(Gtx_t *gtx) override;
     * 
     *     bool alive() override;
     * };
     * 
     * //Use
     * 
     * //Create
     * auto physicsSys = PhysicsSys_t();
     * 
     * //Game Loop
     * 
     * while(...){
     *      .
     *      .
     *      .
     *      physicsSys.update(&gtx);
     *      renderSys.update(&gtx);
     *      inputSys.update();
     *      .
     *      .
     *      .
     * }
     * 
     * //Update Method
     *      void update(Gtx_t *gtx) override{
     *          for (Position2Df_t &cmp : gtx->getComponents<Position2Df_t>())
     *           {
     *               //Any Update cmp Physics
     *           }
     *      }
     * @endcode
     */
     /**
     * @brief Clase de la que heredan todos los Systems del Motor
     * @image html assets/stability/stability_2.png
     * @tparam Type
     */
     template <MOON_IS_CTX_T... Type>
     struct System_t : public SystemBase_t
     {

     public:
          /**
         * @brief Contructor de System_t object
         *
         */
          //TODO:LOGS
          System_t()
          {
               Moon::Tools::Logs::contructor("System_t", this);
          }

          /**
         * @brief Destructor de System_t object
         *
         */
          //TODO:LOGS
          virtual ~System_t()
          {
               Moon::Tools::Logs::destructor("System_t", this);
          }

          /**
         * @brief Get the System Type object
         *
         * @return Moon::Alias::SystemType
         */
          static Moon::Alias::SystemType getSystemType() noexcept;

          /**
         * @brief Metodo que actualiza al System
         *
         * @param gameContext
         */
          virtual void update(Type *...gameContext) = 0;

          /**
         * @brief Metodo que indica si el system sigue alive
         *
         * @return true
         * @return false
         */
          virtual bool alive() = 0;
     };
     /**
     * @subsubsection Example
     * @code{.cpp}
     * struct InputSystem_t : Moon::Core::SystemVoid_t<InputSystem_t>
     * {
     *     bool alive_flag = true;
     * 
     *     void update() override{
     *         if (...)
     *                 this->alive_flag = false;
     *     }
     *     bool alive() override{ return this->alive_flag; }
     * };
     * 
     * //Use
     * 
     * //Create
     * auto inputSys = InputSystem_t();
     * 
     * //Game Loop
     * 
     * while(...){
     *      .
     *      .
     *      .
     *      physicsSys.update(&gtx);
     *      renderSys.update(&gtx);
     *      inputSys.update();
     *      .
     *      .
     *      .
     * }
     * @endcode
     */
     /**
     * @brief Clase de la que heredan todos los SystemVoid del Motor
     * @image html assets/stability/stability_1.png
     * @tparam Type
     */
     template <typename Type>
     struct SystemVoid_t : public SystemBase_t
     {

     public:
          //TODO:LOGS
          SystemVoid_t()
          {
               Moon::Tools::Logs::contructor("SystemVoid_t", this);
          }

          //TODO:LOGS
          virtual ~SystemVoid_t()
          {
               Moon::Tools::Logs::destructor("SystemVoid_t", this);
          }

          static Moon::Alias::SystemType getSystemType() noexcept;

          virtual void update() = 0;

          virtual bool alive() = 0;
     };

} // namespace Moon::Core