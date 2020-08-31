/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 21 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#include "GPIO_interface.h"


static const u32 g_pu32GPIOBaseAddrs[] =
{
    GPIO_A_APB, GPIO_A_AHB,
    GPIO_B_APB, GPIO_B_AHB,
    GPIO_C_APB, GPIO_C_AHB,
    GPIO_D_APB, GPIO_D_AHB,
    GPIO_E_APB, GPIO_E_AHB,
    GPIO_F_APB, GPIO_F_AHB
};
/***************************************************************************************************/
/**                            Static Functions                                                    */
/***************************************************************************************************/
static void GPIO_voidUnlockCommit(u32 Copy_u32GPIOPort)
{
    WR_REG(Copy_u32GPIOPort + GPIO_LOCK, GPIO_COMMIT_UNLOCK);
}

static void GPIO_voidEnablePortCommit(u32 Copy_u32GPIOPort, u8 Copy_u8Value)
{
    WR_REG(Copy_u32GPIOPort + GPIO_CR, Copy_u8Value);
}

static void GPIO_voidEnablePinCommit(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum)
{
    SET_BIT(Copy_u32GPIOPort + GPIO_CR, Copy_u8PinNum);
}

static void GPIO_voidSelectPortAnalogInput(u32 Copy_u32GPIOPort,
                                           u8 Copy_u8Value)
{
    WR_REG(Copy_u32GPIOPort + GPIO_AMSEL, Copy_u8Value);
}

static void GPIO_voidSelectPinAnalogInput(u32 Copy_u32GPIOPort,
                                          u8 Copy_u8PinNum, u8 Copy_u8Value)
{
    switch (Copy_u8Value)
    {
    case ENABLE:
        SET_BIT(Copy_u32GPIOPort + GPIO_AMSEL, Copy_u8PinNum);
        break;
    case DISABLE:
        CLR_BIT(Copy_u32GPIOPort + GPIO_AMSEL, Copy_u8PinNum);
        break;
    default:
        CLR_BIT(Copy_u32GPIOPort + GPIO_AMSEL, Copy_u8PinNum);
        break;
    }
}

/***************************************************************************************************/
/**                            PORT Configuration Functions                                        */
/***************************************************************************************************/
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
    if(Copy_u8OpenDrain || Copy_u8PullDown || Copy_u8PullUp){
        GPIO_voidUnlockCommit(Copy_u32GPIOPort);
        GPIO_voidEnablePortCommit(Copy_u32GPIOPort, Copy_u8OpenDrain | Copy_u8PullDown | Copy_u8PullUp);
    }
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

void GPIO_voidEnabelPortAlternateFunc(u32 Copy_u32GPIOPort ,u8 Copy_u8Value){
    WR_REG(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8Value);
}

void GPIO_voidEnablePortSlewRateControl(u32 Copy_u32GPIOPort ,u8 Copy_u8Value){
    WR_REG(Copy_u32GPIOPort + GPIO_SLR , Copy_u8Value);
}


void GPIO_voidConfigPortAdcSource(u32 Copy_u32GPIOPort , u8 Copy_u8Value ){
    GPIO_voidSelectPortAnalogInput(Copy_u32GPIOPort, Copy_u8Value);
    WR_REG( Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8Value);
}

void GPIO_voidConfigPortDMA(u32 Copy_u32GPIOPort , u8 Copy_u8Value ){
    WR_REG( Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8Value);
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
    if(Copy_u8PinSate){
        GPIO_voidUnlockCommit(Copy_u32GPIOPort);
        GPIO_voidEnablePinCommit(Copy_u32GPIOPort, Copy_u8PinNum);
    }
    switch(Copy_u8PinSate){
    case GPIO_PIN_PULL_UP       : SET_BIT((Copy_u32GPIOPort + GPIO_PUR ), Copy_u8PinNum) ; break ;
    case GPIO_PIN_PULL_DOWN     : SET_BIT((Copy_u32GPIOPort + GPIO_PDR ), Copy_u8PinNum) ; break ;
    case GPIO_PIN_OPEN_DRAIN    : SET_BIT((Copy_u32GPIOPort + GPIO_ODR ), Copy_u8PinNum) ; break ;
    case GPIO_PIN_PUSH_PULL     : CLR_BIT((Copy_u32GPIOPort + GPIO_PUR ), Copy_u8PinNum) ;
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

void GPIO_voidAlternatePinFunc(u32 Copy_u32GPIOPort ,u8 Copy_u8PinNum ,u8 Copy_u8Value){
    switch(Copy_u8Value){
    case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8PinNum) ; break ;
    case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8PinNum) ; break ;
    default      : CLR_BIT(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8PinNum) ; break ;
    }
}

void GPIO_voidControlPinSlewRate(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value){
    switch(Copy_u8Value){
    case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_SLR , Copy_u8PinNum) ; break ;
    case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_SLR , Copy_u8PinNum) ; break ;
    default      : CLR_BIT(Copy_u32GPIOPort + GPIO_SLR , Copy_u8PinNum) ; break ;
    }
}



void GPIO_voidConfigPinAlternateFunc(u32 Copy_u32PinConfig){
    u32 GPIO_base = (Copy_u32PinConfig >>16) & 0xFF;
    u32 shift = 0;
     if( RD_REG(0x400FE06C) & (1 << GPIO_base)){ /** Check if GPIOx AHB enabled. */
          GPIO_base = g_pu32GPIOBaseAddrs[(GPIO_base <<1) +1 ];
     }else{
         GPIO_base = g_pu32GPIOBaseAddrs[(GPIO_base <<1)];
     }
     shift = (Copy_u32PinConfig >> 8) & 0xFF ;
     WR_REG(GPIO_base + GPIO_PCTL , ((RD_REG(GPIO_base + GPIO_PCTL) & ~(0xF << shift)) |
                                     ((Copy_u32PinConfig & 0xF) << shift)));
}

void GPIO_voidConfigPinAdcSource(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum,u8 Copy_u8Value ){
    GPIO_voidSelectPinAnalogInput(Copy_u32GPIOPort, Copy_u8PinNum, Copy_u8Value);
    switch(Copy_u8Value){
    case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8PinNum) ; break ;
    case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8PinNum) ; break ;
    default      : CLR_BIT(Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8PinNum) ; break ;
    }
}

void GPIO_voidConfigPinDMA(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value ){
    switch(Copy_u8Value){
     case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8PinNum) ; break ;
     case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8PinNum) ; break ;
     default      : CLR_BIT(Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8PinNum) ; break ;
     }
}
