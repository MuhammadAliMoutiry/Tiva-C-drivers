/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 31 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
#include "NVIC_private.h"
/**
Copy_u8InterruptID is value from :
                                    NVIC_GPIOA_ID
                                    NVIC_GPIOB_ID
                                    NVIC_GPIOC_ID
                                    NVIC_GPIOD_ID
                                    NVIC_GPIOE_ID
                                    NVIC_UART0_ID
                                    NVIC_UART1_ID
                                    NVIC_SSI0_ID
                                    NVIC_I2C0_ID
                                    NVIC_PWM0_FAULT_ID
                                    NVIC_PWM0_GENERATOR0_ID
                                    NVIC_PWM0_GENERATOR1_ID
                                    NVIC_PWM0_GENERATOR2_ID
                                    NVIC_QEI0_ID
                                    NVIC_ADC0_SEQUENCE0_ID
                                    NVIC_ADC0_SEQUENCE1_ID
                                    NVIC_ADC0_SEQUENCE2_ID
                                    NVIC_ADC0_SEQUENCE3_ID
                                    NVIC_WATCHFOG_TIMERS0_AND_1
                                    NVIC_16_32_BIT_TIMER_0A_ID
                                    NVIC_16_32_BIT_TIMER_0B_ID
                                    NVIC_16_32_BIT_TIMER_1A_ID
                                    NVIC_16_32_BIT_TIMER_1B_ID
                                    NVIC_16_32_BIT_TIMER_2A_ID
                                    NVIC_16_32_BIT_TIMER_2B_ID
                                    NVIC_ANALOG_COMPARATOR_0_ID
                                    NVIC_ANALOG_COMPARATOR_1_ID
                                    NVIC_SYSTEM_CONTROL_ID
                                    NVIC_FLASH_AND_EEPROM_CONTR
                                    NVIC_GPIO_F_ID
                                    NVIC_UART2_ID
                                    NVIC_SSI1_ID
                                    NVIC_16_32_BIT_TIMER_3A_ID
                                    NVIC_16_32_BIT_TIMER_3B_ID
                                    NVIC_I2C1_ID
                                    NVIC_QEI1_ID
                                    NVIC_CAN0_ID
                                    NVIC_CAN1_ID
                                    NVIC_HIBERNATION_MODULE_ID
                                    NVIC_USB_ID
                                    NVIC_PWM_GENERATOR_3_ID
                                    NVIC_MICRO_DMA_SOFTWARE_ID
                                    NVIC_MICRO_DMA_ERROE_ID
                                    NVIC_ADC1_SEQUENCE_0_ID
                                    NVIC_ADC1_SEQUENCE_1_ID
                                    NVIC_ADC1_SEQUENCE_2_ID
                                    NVIC_ADC1_SEQUENCE_3_ID
                                    NVIC_SSI2_ID
                                    NVIC_SSI3_ID
                                    NVIC_UART3_ID
                                    NVIC_UART4_ID
                                    NVIC_UART5_ID
                                    NVIC_UART6_ID
                                    NVIC_UART7_ID
                                    NVIC_I2C2_ID
                                    NVIC_I2C3_ID
                                    NVIC_16_32_BIT_TIMER_4A_ID
                                    NVIC_16_32_BIT_TIMER_4B_ID
                                    NVIC_16_32_BIT_TIMER_5A_ID
                                    NVIC_16_32_BIT_TIMER_5B_ID
                                    NVIC_32_64_BIT_TIMER_0A_ID
                                    NVIC_32_64_BIT_TIMER_0B_ID
                                    NVIC_32_64_BIT_TIMER_1A_ID
                                    NVIC_32_64_BIT_TIMER_1B_ID
                                    NVIC_32_64_BIT_TIMER_2A_ID
                                    NVIC_32_64_BIT_TIMER_2B_ID
                                    NVIC_32_64_BIT_TIMER_3A_ID
                                    NVIC_32_64_BIT_TIMER_3B_ID
                                    NVIC_32_64_BIT_TIMER_4A_ID
                                    NVIC_32_64_BIT_TIMER_4B_ID
                                    NVIC_32_64_BIT_TIMER_5A_ID
                                    NVIC_32_64_BIT_TIMER_5B_ID
                                    NVIC_SYSTEM_EXCEPTION_ID
                                    NVIC_PWM1_GENERATOR_0_ID
                                    NVIC_PWM1_GENERATOR_1_ID
                                    NVIC_PWM1_GENERATOR_2_ID
                                    NVIC_PWM1_GENERATOR_3_ID
                                    NVIC_PWM1_FAULT_ID
*/

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptID);
void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptID);
void MNVIC_voidSetInterruptPendingFlag(u8 Copy_u8InterruptID);
void MNVIC_voidClearInterruptPendingFlag(u8 Copy_u8InterruptID);
u32  MNVIC_u32GetActiveFlag(u8 Copy_u8InterruptID);
void MNVIC_voidSetPriority(u8 Copy_u8InterruptID ,u8 Copy_u8Priority);
void MNVIC_voidTriggerSoftwareInterrupt(u8 Copy_u8InterruptID);

#endif /* NVIC_INTERFACE_H_ */
