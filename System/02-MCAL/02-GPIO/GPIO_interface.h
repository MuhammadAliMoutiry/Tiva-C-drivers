
/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 21 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_config.h"
#include "GPIO_reg.h"
#include "GPIO_private.h"

/**************************************************************************************************/
/**********************************  Port Public Functions ****************************************/
/**************************************************************************************************/

/**
 * @name     :  MGPIO_voidInitPort
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
void MGPIO_voidInitPort(u32 Copy_u32GPIOPort, u8 Copy_u8PortDir);

/**
 * @name    :  MGPIO_voidPortSelCurrent
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
 * @param   :  u8 Copy_u8SelCurrent          -> Options : GPIO_2M_DRIVE_CURRENT
 *                                                        GPIO_4M_DRIVE_CURRENT
 *                                                        GPIO_8M_DRIVE_CURRENT
 *
 * @return  :  No return value
 * @details :  this function select the current for the whole GPIO pins , the whole pins will drive
 *             the same current.
 */
void MGPIO_voidPortSelCurrent(u32 Copy_u32GPIOPort, u8 Copy_u8SelCurrent);

/**
 * @name    :  MGPIO_voidSelPortState
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
void MGPIO_voidSelPortState(u32 Copy_u32GPIOPort, u8 Copy_u8OpenDrain, u8 Copy_u8PullUp, u8 Copy_u8PullDown);

/**
 * @name    :  MGPIO_voidEnablePort
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
void MGPIO_voidEnablePort(u32 Copy_u32GPIOPort);

/**
 * @name    :  MGPIO_voidWritePort
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
void MGPIO_voidWritePort(u32 Copy_u32GPIOPort , u8 Copy_u8Value);

/**
 * @name    :  MGPIO_u8ReadPort
 * @brief   :  This function reads data from GPIO port.
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
 *
 * @return   :  8 bit data
 */
u8 MGPIO_u8ReadPort(u32 Copy_u32GPIOPort );

/**
 * @name    :  MGPIO_voidEnabelPortAlternateFunc
 * @brief   :  This function enable alternative functionality for a GPIO port.
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
 * @param  :  Copy_u8Value -> value to enable or disable Alternative functions.
 */
void MGPIO_voidEnabelPortAlternateFunc(u32 Copy_u32GPIOPort ,u8 Copy_u8Value);

/**
 * @name    :  MGPIO_voidEnablePortSlewRateControl
 * @brief   :  This function enable slew rate control for a GPIO port.
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
 * @param  :  Copy_u8Value -> value to enable or disable slew rate control.
 */
void MGPIO_voidEnablePortSlewRateControl(u32 Copy_u32GPIOPort ,u8 Copy_u8Value);

/**************************************************************************************************/
/**********************************  Pin Public Functions ****************************************/
/**************************************************************************************************/

/**
 * @name    :  MGPIO_voidInitPin
 * @brief   :  This function initialize pin direction.
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
 * @param  :  Copy_u8PinNum ->    pin numbers from 0 to 8
 * @param  :  Copy_u8Value  ->    Options :   INPUT
 *                                            OUTPUT
 */
void MGPIO_voidInitPin(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum, u8 Copy_u8PinDir);

/**
 * @name    :  MGPIO_voidSelPinCurrent
 * @brief   :  This function selects pin drive current.
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
 * @param  :  Copy_u8PinNum      ->    pin numbers from 0 to 8
 * @param  :  Copy_u8SelCurrent  ->    Options :   GPIO_2M_DRIVE_CURRENT
 *                                                 GPIO_4M_DRIVE_CURRENT
 *                                                 GPIO_8M_DRIVE_CURRENT
 */
void MGPIO_voidSelPinCurrent(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum,u8 Copy_u8SelCurrent);

/**
 * @name    :  MGPIO_voidSelPinState
 * @brief   :  This function selects pin state pull up,pull down and open drain.
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
 * @param  :  Copy_u8PinNum   ->    pin numbers from 0 to 8
 * @param  :  Copy_u8PinSate  ->    Options :   GPIO_PIN_PUSH_PULL
 *                                              GPIO_PIN_PULL_UP
 *                                              GPIO_PIN_PULL_DOWN
 *                                              GPIO_PIN_OPEN_DRAIN
 */
void MGPIO_voidSelPinState(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum, u8 Copy_u8PinSate);

/**
 * @name    :  MGPIO_voidEnablePin
 * @brief   :  This function enables a specific GPIO pin.
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
 * @param  :  Copy_u8PinNum   ->    pin numbers from 0 to 8
 */
void MGPIO_voidEnablePin(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum);

/**
 * @name    :  MGPIO_voidWritePin
 * @brief   :  This function writes value to a specific GPIO pin.
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
 * @param  :  Copy_u8PinNum   ->    pin numbers from 0 to 8
 * @param  :  Copy_u8Value    ->    Options : LOW
 *                                            HIGH
 */
void MGPIO_voidWritePin(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value);

/**
 * @name    :  MGPIO_u8ReadPin
 * @brief   :  This function reads value from a specific GPIO pin.
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
 * @param  :  Copy_u8PinNum   ->    pin numbers from 0 to 8
 * @return :  pin value       ->    Options : HIGH -> 1
 *                                            LOW  -> 0
 */
u8 MGPIO_u8ReadPin(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum );

/**
 * @name    :  MGPIO_voidAlternatePinFunc
 * @brief   :  This function enable/disable GPIO pin alternate function.
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
 * @param  :  Copy_u8PinNum   ->    pin numbers from 0 to 8
 * @param  :  Copy_u8Value    ->    Options : Enable
 *                                            Disable
 */
void MGPIO_voidAlternatePinFunc(u32 Copy_u32GPIOPort ,u8 Copy_u8PinNum ,u8 Copy_u8Value);

/**
 * @name    :  MGPIO_voidControlPinSlewRate
 * @brief   :  This function enable/disable GPIO pin slew rate control.
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
 * @param  :  Copy_u8PinNum   ->    pin numbers from 0 to 8
 * @param  :  Copy_u8Value    ->    Options : Enable
 *                                            Disable
 */
void MGPIO_voidControlPinSlewRate(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value);

/**
 * @name    :  MGPIO_voidConfigPinAlternateFunc
 * @brief   :  This function select the alternative functionality of a GPIO pin.
 * @param   :  Copy_u32PinConfig          -> Options :  GPIO_PA0_U0RX
 *                                                      GPIO_PA0_CAN1RX
 *
 *                                                      GPIO_PA1_U0TX
 *                                                      GPIO_PA1_CAN1TX
 *
 *                                                      GPIO_PA2_SSI0CLK
 *
 *                                                      GPIO_PA3_SSI0FSS
 *
 *                                                      GPIO_PA4_SSI0RX
 *
 *                                                      GPIO_PA5_SSI0TX
 *
 *                                                      GPIO_PA6_I2C1SCL
 *                                                      GPIO_PA6_M1PWM2
 *
 *                                                      GPIO_PA7_I2C1SDA
 *                                                      GPIO_PA7_M1PWM3
 ****************************************************
 *                                                      GPIO_PB0_U1RX
 *                                                      GPIO_PB0_T2CCP0
 *
 *                                                      GPIO_PB1_U1TX
 *                                                      GPIO_PB1_T2CCP1
 *
 *                                                      GPIO_PB2_I2C0SCL
 *                                                      GPIO_PB2_T3CCP0
 *
 *                                                      GPIO_PB3_I2C0SDA
 *                                                      GPIO_PB3_T3CCP1
 *
 *                                                      GPIO_PB4_SSI2CLK
 *                                                      GPIO_PB4_M0PWM2
 *                                                      GPIO_PB4_T1CCP0
 *                                                      GPIO_PB4_CAN0RX
 *
 *                                                      GPIO_PB5_SSI2FSS
 *                                                      GPIO_PB5_M0PWM3
 *                                                      GPIO_PB5_T1CCP1
 *                                                      GPIO_PB5_CAN0TX
 *
 *                                                      GPIO_PB6_SSI2RX
 *                                                      GPIO_PB6_M0PWM0
 *                                                      GPIO_PB6_T0CCP0
 *
 *                                                      GPIO_PB7_SSI2TX
 *                                                      GPIO_PB7_M0PWM1
 *                                                      GPIO_PB7_T0CCP1
 ******************************************************
 *                                                      GPIO_PC0_TCK
 *                                                      GPIO_PC0_SWCLK
 *                                                      GPIO_PC0_T4CCP0
 *
 *                                                      GPIO_PC1_TMS
 *                                                      GPIO_PC1_SWDIO
 *                                                      GPIO_PC1_T4CCP1
 *
 *                                                      GPIO_PC2_TDI
 *                                                      GPIO_PC2_T5CCP0
 *
 *                                                      GPIO_PC3_SWO
 *                                                      GPIO_PC3_TDO
 *                                                      GPIO_PC3_T5CCP1
 *
 *                                                      GPIO_PC4_U4RX
 *                                                      GPIO_PC4_U1RX
 *                                                      GPIO_PC4_M0PWM6
 *                                                      GPIO_PC4_IDX1
 *                                                      GPIO_PC4_WT0CCP0
 *                                                      GPIO_PC4_U1RTS
 *
 *                                                      GPIO_PC5_U4TX
 *                                                      GPIO_PC5_U1TX
 *                                                      GPIO_PC5_M0PWM7
 *                                                      GPIO_PC5_PHA1
 *                                                      GPIO_PC5_WT0CCP1
 *                                                      GPIO_PC5_U1CTS
 *
 *                                                      GPIO_PC6_U3RX
 *                                                      GPIO_PC6_PHB1
 *                                                      GPIO_PC6_WT1CCP0
 *                                                      GPIO_PC6_USB0EPEN
 *
 *                                                      GPIO_PC7_U3TX
 *                                                      GPIO_PC7_WT1CCP1
 *                                                      GPIO_PC7_USB0PFLT
 *******************************************************
 *                                                      GPIO_PD0_SSI3CLK
 *                                                      GPIO_PD0_SSI1CLK
 *                                                      GPIO_PD0_I2C3SCL
 *                                                      GPIO_PD0_M0PWM6
 *                                                      GPIO_PD0_M1PWM0
 *                                                      GPIO_PD0_WT2CCP0
 *
 *                                                      GPIO_PD1_SSI3FSS
 *                                                      GPIO_PD1_SSI1FSS
 *                                                      GPIO_PD1_I2C3SDA
 *                                                      GPIO_PD1_M0PWM7
 *                                                      GPIO_PD1_M1PWM1
 *                                                      GPIO_PD1_WT2CCP1
 *
 *                                                      GPIO_PD2_SSI3RX
 *                                                      GPIO_PD2_SSI1RX
 *                                                      GPIO_PD2_M0FAULT0
 *                                                      GPIO_PD2_WT3CCP0
 *                                                      GPIO_PD2_USB0EPEN
 *
 *                                                      GPIO_PD3_SSI3TX
 *                                                      GPIO_PD3_SSI1TX
 *                                                      GPIO_PD3_IDX0
 *                                                      GPIO_PD3_WT3CCP1
 *                                                      GPIO_PD3_USB0PFLT
 *
 *                                                      GPIO_PD4_U6RX
 *                                                      GPIO_PD4_WT4CCP0
 *
 *                                                      GPIO_PD5_U6TX
 *                                                      GPIO_PD5_WT4CCP1
 *
 *                                                      GPIO_PD6_U2RX
 *                                                      GPIO_PD6_M0FAULT0
 *                                                      GPIO_PD6_PHA0
 *                                                      GPIO_PD6_WT5CCP0
 *
 *                                                      GPIO_PD7_U2TX
 *                                                      GPIO_PD7_PHB0
 *                                                      GPIO_PD7_WT5CCP1
 *                                                      GPIO_PD7_NMI
 *******************************************************
 *                                                      GPIO_PE0_U7RX
 *
 *                                                      GPIO_PE1_U7TX
 *
 *                                                      GPIO_PE4_U5RX
 *                                                      GPIO_PE4_I2C2SCL
 *                                                      GPIO_PE4_M0PWM4
 *                                                      GPIO_PE4_M1PWM2
 *                                                      GPIO_PE4_CAN0RX
 *
 *                                                      GPIO_PE5_U5TX
 *                                                      GPIO_PE5_I2C2SDA
 *                                                      GPIO_PE5_M0PWM5
 *                                                      GPIO_PE5_M1PWM3
 *                                                      GPIO_PE5_CAN0TX
 ******************************************************
 *                                                      GPIO_PF0_U1RTS
 *                                                      GPIO_PF0_SSI1RX
 *                                                      GPIO_PF0_CAN0RX
 *                                                      GPIO_PF0_M1PWM4
 *                                                      GPIO_PF0_PHA0
 *                                                      GPIO_PF0_T0CCP0
 *                                                      GPIO_PF0_NMI
 *                                                      GPIO_PF0_C0O
 *
 *                                                      GPIO_PF1_U1CTS
 *                                                      GPIO_PF1_SSI1TX
 *                                                      GPIO_PF1_M1PWM5
 *                                                      GPIO_PF1_PHB0
 *                                                      GPIO_PF1_T0CCP1
 *                                                      GPIO_PF1_C1O
 *                                                      GPIO_PF1_TRD1
 *
 *                                                      GPIO_PF2_SSI1CLK
 *                                                      GPIO_PF2_M0FAULT0
 *                                                      GPIO_PF2_M1PWM6
 *                                                      GPIO_PF2_T1CCP0
 *                                                      GPIO_PF2_TRD0
 *
 *                                                      GPIO_PF3_SSI1FSS
 *                                                      GPIO_PF3_CAN0TX
 *                                                      GPIO_PF3_M1PWM7
 *                                                      GPIO_PF3_T1CCP1
 *                                                      GPIO_PF3_TRCLK
 *
 *                                                      GPIO_PF4_M1FAULT0
 *                                                      GPIO_PF4_IDX0
 *                                                      GPIO_PF4_T2CCP0
 *                                                      GPIO_PF4_USB0EPEN
 *
 */
void MGPIO_voidConfigPinAlternateFunc(u32 Copy_u32PinConfig);



 void MGPIO_voidEnableExtInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum);
 void MGPIO_voidDisableExtInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum);

 /**  Copy_u8InterruptSense Options :    GPIO_INTERRUPT_LOW_LEVEL
  *                                      GPIO_INTERRUPT_HIGH_LEVEL
  *                                      GPIO_INTERRUPT_FALLING_EDGE
  *                                      GPIO_INTERRUPT_RISING_EDGE
  *                                      GPIO_INTERRUPT_BOTH_EDGES
  *
  *
  * */

 void MGPIO_voidInitInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8InterruptSense );
 u8 MGPIO_voidGetPortRawInterruptStatus(u32 Copy_u32GPIOPort);
 u8 MGPIO_voidGetPinRawInterruptStatus(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum);
 u8 MGPIO_voidGetPortMaskInterruptStatus(u32 Copy_u32GPIOPort);
 u8 MGPIO_voidGetPinMaskInterruptStatus(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum);
 void MGPIO_voidClearInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum);
#endif /* GPIO_INTERFACE_H_ */
