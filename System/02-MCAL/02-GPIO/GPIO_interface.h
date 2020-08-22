
/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 21 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_reg.h"

/**
 * @name     :  GPIO_voidInitPort
 * @brief    :  This function initializes port ( INPUT and OUTPUT ) pins
 * @param    :  Copy_u32GPIOPort   -> Options :   GPIO_A_APB
 *                                                GPIO_A_AHB
 *                                                GPIO_B_APB
 *                                                GPIO_B_AHB
 *                                                GPIO_C_APB
 *                                                GPIO_C_AHB
 *                                                GPIO_D_APB
 *                                                GPIO_D_AHB
 *                                                GPIO_E_APB
 *                                                GPIO_E_AHB
 *                                                GPIO_F_APB
 *                                                GPIO_F_AHB
 *
 * @param   :  Copy_u8PortDir  -> Direction of the GPIO port pins.
 * @return  :  No return value
 * @details :  In order to use this function and the others the PORTx clock must be enabled
 * @see     :  SYSCTRL_voidEnableClock
 * @note    :  Using x_x_AHB needs to allow AHB bus access throw system control peripheral.
 */
void GPIO_voidInitPort(u32 Copy_u32GPIOPort, u8 Copy_u8PortDir);

/**
 * @name    :  GPIO_voidPortSelCurrent
 * @brief   :  Select drive current for the whole GPIO port pins
 * @param   :  Copy_u32GPIOPort            -> Options :   GPIO_A_APB
 *                                                        GPIO_A_AHB
 *                                                        GPIO_B_APB
 *                                                        GPIO_B_AHB
 *                                                        GPIO_C_APB
 *                                                        GPIO_C_AHB
 *                                                        GPIO_D_APB
 *                                                        GPIO_D_AHB
 *                                                        GPIO_E_APB
 *                                                        GPIO_E_AHB
 *                                                        GPIO_F_APB
 *                                                        GPIO_F_AHB
 *
 * @param   :  Copy_GPIOCurrent_tSelCurrent  -> Options : GPIO_2M_DRIVE_CURRENT
 *                                                        GPIO_4M_DRIVE_CURRENT
 *                                                        GPIO_8M_DRIVE_CURRENT
 *
 * @return  :  No return value
 * @details :  this function select the current for the whole GPIO pins , the whole pins will drive
 *             the same current.
 */
void GPIO_voidPortSelCurrent(u32 Copy_u32GPIOPort, GPIOCurrent_t Copy_GPIOCurrent_tSelCurrent);

/**
 * @name    :  GPIO_voidSelPortOutState
 * @brief   :  This function selects all GPIO pin state pull up ,pull down and open drain.
 * @param   :  Copy_u32GPIOPort            -> Options :   GPIO_A_APB
 *                                                        GPIO_A_AHB
 *                                                        GPIO_B_APB
 *                                                        GPIO_B_AHB
 *                                                        GPIO_C_APB
 *                                                        GPIO_C_AHB
 *                                                        GPIO_D_APB
 *                                                        GPIO_D_AHB
 *                                                        GPIO_E_APB
 *                                                        GPIO_E_AHB
 *                                                        GPIO_F_APB
 *                                                        GPIO_F_AHB
 *
 * @param   :  Copy_u8OpenDrain    -> select open drain pins
 * @param   :  Copy_u8PullUp       -> select pull up pins
 * @param   :  Copy_u8PullDown     -> select pull down pins
 * @return  :  No return value
 * @details :  configure pin state
 * @note    :  GPIO pin has only one state at a time ,you can not configure a GPIO in more than
 *             one state at a time.
 */
void GPIO_voidSelPortOutState(u32 Copy_u32GPIOPort, u8 Copy_u8OpenDrain, u8 Copy_u8PullUp, u8 Copy_u8PullDown);

/**
 * @name    :  GPIO_voidEnablePort
 * @brief   :  This function Enables a GPIO port.
 * @param   :  Copy_u32GPIOPort            -> Options :   GPIO_A_APB
 *                                                        GPIO_A_AHB
 *                                                        GPIO_B_APB
 *                                                        GPIO_B_AHB
 *                                                        GPIO_C_APB
 *                                                        GPIO_C_AHB
 *                                                        GPIO_D_APB
 *                                                        GPIO_D_AHB
 *                                                        GPIO_E_APB
 *                                                        GPIO_E_AHB
 *                                                        GPIO_F_APB
 *                                                        GPIO_F_AHB
 * @return   :  no return value
 */
void GPIO_voidEnablePort(u32 Copy_u32GPIOPort);

/**
 * @name    :  GPIO_voidWritePort
 * @brief   :  This function writes date to GPIO port.
 * @param   :  Copy_u32GPIOPort            -> Options :   GPIO_A_APB
 *                                                        GPIO_A_AHB
 *                                                        GPIO_B_APB
 *                                                        GPIO_B_AHB
 *                                                        GPIO_C_APB
 *                                                        GPIO_C_AHB
 *                                                        GPIO_D_APB
 *                                                        GPIO_D_AHB
 *                                                        GPIO_E_APB
 *                                                        GPIO_E_AHB
 *                                                        GPIO_F_APB
 *                                                        GPIO_F_AHB
 *
 * @param   :  Copy_u8Value  -> values to be written on GPIO port
 *
 */
void GPIO_voidWritePort(u32 Copy_u32GPIOPort , u8 Copy_u8Value);


#endif /* GPIO_INTERFACE_H_ */
