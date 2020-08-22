/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 21 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#include "GPIO_interface.h"

void GPIO_voidInitPort(u32 Copy_u32GPIOPort, u8 Copy_u8PortDir){
    WR_REG(Copy_u32GPIOPort + GPIO_DIR , Copy_u8PortDir);
}

void GPIO_voidSelPortCurrent(u32 Copy_u32GPIOPort, GPIOCurrent_t Copy_GPIOCurrent_tSelCurrent){
    switch (Copy_GPIOCurrent_tSelCurrent){
        case GPIO_2M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR2R); break ;
        case GPIO_4M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR4R); break ;
        case GPIO_8M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR8R); break ;
        default                    : SET_REG(Copy_u32GPIOPort + GPIO_DR2R); break ;
        }
}

void GPIO_voidSelPortOutState(u32 Copy_u32GPIOPort, u8 Copy_u8OpenDrain, u8 Copy_u8PullUp, u8 Copy_u8PullDown){
    WR_REG(Copy_u32GPIOPort + GPIO_ODR , Copy_u8OpenDrain);
    WR_REG(Copy_u32GPIOPort + GPIO_PUR , Copy_u8PullUp   );
    WR_REG(Copy_u32GPIOPort + GPIO_PDR , Copy_u8PullDown );
}

void GPIO_voidEnablePort(u32 Copy_u32GPIOPort){
    SET_REG(Copy_u32GPIOPort + GPIO_DEN);
}

void GPIO_voidWritePort(u32 Copy_u32GPIOPort , u8 Copy_u8Value){
    WR_REG(Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK, Copy_u8Value);
}
