/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 21 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#include "GPIO_interface.h"

void GPIO_voidInitPort(u32 Copy_u32GPIOPort, u8 Copy_u8PortDir){
    WR_REG(Copy_u32GPIOPort + GPIO_DIR , Copy_u8PortDir);
}

void GPIO_voidSelPortCurrent(u32 Copy_u32GPIOPort, u8 Copy_u8SelCurrent){
    switch (Copy_u8SelCurrent){
        case GPIO_2M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR2R); break ;
        case GPIO_4M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR4R); break ;
        case GPIO_8M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR8R); break ;
        default                    : SET_REG(Copy_u32GPIOPort + GPIO_DR2R); break ;
        }
}

void GPIO_voidSelPortState(u32 Copy_u32GPIOPort, u8 Copy_u8OpenDrain, u8 Copy_u8PullUp, u8 Copy_u8PullDown){
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

u8 GPIO_u8ReadPort(u32 Copy_u32GPIOPort ){
    return RD_REG(Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK);
}

/*****************************************************************************************************/
/**                                 GPIO single Pin Functions                                        */
/*****************************************************************************************************/
void GPIO_voidInitPin(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum, u8 Copy_u8PinDir){
    switch(Copy_u8PinDir){
    case INPUT  : CLR_BIT((Copy_u32GPIOPort + GPIO_DIR) , Copy_u8PinNum); break ;
    case OUTPUT : SET_BIT((Copy_u32GPIOPort + GPIO_DIR) , Copy_u8PinNum); break ;
    default     : CLR_BIT((Copy_u32GPIOPort + GPIO_DIR) , Copy_u8PinNum); break ;
    }

}

void GPIO_voidSelPinCurrent(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum,u8 Copy_u8SelCurrent){
    switch (Copy_u8SelCurrent){
        case GPIO_2M_DRIVE_CURRENT : SET_BIT(Copy_u32GPIOPort + GPIO_DR2R ,Copy_u8PinNum); break ;
        case GPIO_4M_DRIVE_CURRENT : SET_BIT(Copy_u32GPIOPort + GPIO_DR4R ,Copy_u8PinNum); break ;
        case GPIO_8M_DRIVE_CURRENT : SET_BIT(Copy_u32GPIOPort + GPIO_DR8R ,Copy_u8PinNum); break ;
        default                    : SET_BIT(Copy_u32GPIOPort + GPIO_DR2R ,Copy_u8PinNum); break ;
        }
}

void GPIO_voidSelPinState(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum, u8 Copy_u8PinSate){
    switch(Copy_u8PinSate){
    case GPIO_PIN_PULL_UP       : SET_BIT((Copy_u32GPIOPort + GPIO_PUR ), Copy_u8PinNum) ; break ;
    case GPIO_PIN_PULL_DOWN     : SET_BIT((Copy_u32GPIOPort + GPIO_PDR ), Copy_u8PinNum) ; break ;
    case GPIO_PIN_OPEN_DRAIN    : SET_BIT((Copy_u32GPIOPort + GPIO_ODR ), Copy_u8PinNum) ; break ;
    case GPIO_PIN_NO_PULL_DRAIN : CLR_BIT((Copy_u32GPIOPort + GPIO_PUR ), Copy_u8PinNum) ;
                                  CLR_BIT((Copy_u32GPIOPort + GPIO_PDR ), Copy_u8PinNum) ;
                                  CLR_BIT((Copy_u32GPIOPort + GPIO_ODR ), Copy_u8PinNum) ; break ;
    }
}

void GPIO_voidEnablePin(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum){
    SET_BIT((Copy_u32GPIOPort + GPIO_DEN) , Copy_u8PinNum);
}

void GPIO_voidWritePin(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value){
    switch(Copy_u8Value){
    case LOW  : CLR_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK) , Copy_u8PinNum) ; break ;
    case HIGH : SET_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK) , Copy_u8PinNum) ; break ;
    default   : CLR_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK) , Copy_u8PinNum) ; break ;
    }
}

u8 GPIO_u8ReadPin(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum ){
    return GET_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK ), Copy_u8PinNum);
}

