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
static void MGPIO_voidUnlockCommit(u32 Copy_u32GPIOPort)
{
    WR_REG(Copy_u32GPIOPort + GPIO_LOCK, GPIO_COMMIT_UNLOCK);
}

static void MGPIO_voidEnablePortCommit(u32 Copy_u32GPIOPort, u8 Copy_u8Value)
{
    WR_REG(Copy_u32GPIOPort + GPIO_CR, Copy_u8Value);
}

static void MGPIO_voidEnablePinCommit(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum)
{
    SET_BIT(Copy_u32GPIOPort + GPIO_CR, Copy_u8PinNum);
}

static void MGPIO_voidSelectPortAnalogInput(u32 Copy_u32GPIOPort,
                                           u8 Copy_u8Value)
{
    WR_REG(Copy_u32GPIOPort + GPIO_AMSEL, Copy_u8Value);
}

static void MGPIO_voidSelectPinAnalogInput(u32 Copy_u32GPIOPort,
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
void MGPIO_voidInitPort(u32 Copy_u32GPIOPort, u8 Copy_u8PortDir){
    WR_REG(Copy_u32GPIOPort + GPIO_DIR , Copy_u8PortDir);
}

void MGPIO_voidSelPortCurrent(u32 Copy_u32GPIOPort, u8 Copy_u8SelCurrent){
    switch (Copy_u8SelCurrent){
        case GPIO_2M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR2R); break ;
        case GPIO_4M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR4R); break ;
        case GPIO_8M_DRIVE_CURRENT : SET_REG(Copy_u32GPIOPort + GPIO_DR8R); break ;
        default                    : SET_REG(Copy_u32GPIOPort + GPIO_DR2R); break ;
        }
}

void MGPIO_voidSelPortState(u32 Copy_u32GPIOPort, u8 Copy_u8OpenDrain, u8 Copy_u8PullUp, u8 Copy_u8PullDown){
    if(Copy_u8OpenDrain || Copy_u8PullDown || Copy_u8PullUp){
        MGPIO_voidUnlockCommit(Copy_u32GPIOPort);
        MGPIO_voidEnablePortCommit(Copy_u32GPIOPort, Copy_u8OpenDrain | Copy_u8PullDown | Copy_u8PullUp);
    }
    WR_REG(Copy_u32GPIOPort + GPIO_ODR , Copy_u8OpenDrain);
    WR_REG(Copy_u32GPIOPort + GPIO_PUR , Copy_u8PullUp   );
    WR_REG(Copy_u32GPIOPort + GPIO_PDR , Copy_u8PullDown );
}

void MGPIO_voidEnablePort(u32 Copy_u32GPIOPort){
    SET_REG(Copy_u32GPIOPort + GPIO_DEN);
}

void MGPIO_voidWritePort(u32 Copy_u32GPIOPort , u8 Copy_u8Value){
    WR_REG(Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK, Copy_u8Value);
}

u8 MGPIO_u8ReadPort(u32 Copy_u32GPIOPort ){
    return RD_REG(Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK);
}

void MGPIO_voidEnabelPortAlternateFunc(u32 Copy_u32GPIOPort ,u8 Copy_u8Value){
    WR_REG(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8Value);
}

void MGPIO_voidEnablePortSlewRateControl(u32 Copy_u32GPIOPort ,u8 Copy_u8Value){
    WR_REG(Copy_u32GPIOPort + GPIO_SLR , Copy_u8Value);
}


void MGPIO_voidConfigPortAdcSource(u32 Copy_u32GPIOPort , u8 Copy_u8Value ){
    MGPIO_voidSelectPortAnalogInput(Copy_u32GPIOPort, Copy_u8Value);
    WR_REG( Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8Value);
}

void MGPIO_voidConfigPortDMA(u32 Copy_u32GPIOPort , u8 Copy_u8Value ){
    WR_REG( Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8Value);
}
/*****************************************************************************************************/
/**                                 GPIO single Pin Functions                                        */
/*****************************************************************************************************/
void MGPIO_voidInitPin(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum, u8 Copy_u8PinDir){
    switch(Copy_u8PinDir){
    case INPUT  : CLR_BIT((Copy_u32GPIOPort + GPIO_DIR) , Copy_u8PinNum); break ;
    case OUTPUT : SET_BIT((Copy_u32GPIOPort + GPIO_DIR) , Copy_u8PinNum); break ;
    default     : CLR_BIT((Copy_u32GPIOPort + GPIO_DIR) , Copy_u8PinNum); break ;
    }

}

void MGPIO_voidSelPinCurrent(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum,u8 Copy_u8SelCurrent){
    switch (Copy_u8SelCurrent){
        case GPIO_2M_DRIVE_CURRENT : SET_BIT(Copy_u32GPIOPort + GPIO_DR2R ,Copy_u8PinNum); break ;
        case GPIO_4M_DRIVE_CURRENT : SET_BIT(Copy_u32GPIOPort + GPIO_DR4R ,Copy_u8PinNum); break ;
        case GPIO_8M_DRIVE_CURRENT : SET_BIT(Copy_u32GPIOPort + GPIO_DR8R ,Copy_u8PinNum); break ;
        default                    : SET_BIT(Copy_u32GPIOPort + GPIO_DR2R ,Copy_u8PinNum); break ;
        }
}

void MGPIO_voidSelPinState(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum, u8 Copy_u8PinSate){
    if(Copy_u8PinSate){
        MGPIO_voidUnlockCommit(Copy_u32GPIOPort);
        MGPIO_voidEnablePinCommit(Copy_u32GPIOPort, Copy_u8PinNum);
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

void MGPIO_voidEnablePin(u32 Copy_u32GPIOPort, u8 Copy_u8PinNum){
    SET_BIT((Copy_u32GPIOPort + GPIO_DEN) , Copy_u8PinNum);
}

void MGPIO_voidWritePin(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value){
    switch(Copy_u8Value){
    case LOW  : CLR_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK) , Copy_u8PinNum) ; break ;
    case HIGH : SET_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK) , Copy_u8PinNum) ; break ;
    default   : CLR_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK) , Copy_u8PinNum) ; break ;
    }
}

u8 MGPIO_u8ReadPin(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum ){
    return GET_BIT((Copy_u32GPIOPort + GPIO_DATA + GPIO_DATA_MASK ), Copy_u8PinNum);
}

void MGPIO_voidAlternatePinFunc(u32 Copy_u32GPIOPort ,u8 Copy_u8PinNum ,u8 Copy_u8Value){
    switch(Copy_u8Value){
    case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8PinNum) ; break ;
    case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8PinNum) ; break ;
    default      : CLR_BIT(Copy_u32GPIOPort + GPIO_AFSEL , Copy_u8PinNum) ; break ;
    }
}

void MGPIO_voidControlPinSlewRate(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value){
    switch(Copy_u8Value){
    case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_SLR , Copy_u8PinNum) ; break ;
    case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_SLR , Copy_u8PinNum) ; break ;
    default      : CLR_BIT(Copy_u32GPIOPort + GPIO_SLR , Copy_u8PinNum) ; break ;
    }
}



void MGPIO_voidConfigPinAlternateFunc(u32 Copy_u32PinConfig){
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

void MGPIO_voidConfigPinAdcSource(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum,u8 Copy_u8Value ){
    MGPIO_voidSelectPinAnalogInput(Copy_u32GPIOPort, Copy_u8PinNum, Copy_u8Value);
    switch(Copy_u8Value){
    case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8PinNum) ; break ;
    case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8PinNum) ; break ;
    default      : CLR_BIT(Copy_u32GPIOPort + GPIO_ADCCTL , Copy_u8PinNum) ; break ;
    }
}

void MGPIO_voidConfigPinDMA(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8Value ){
    switch(Copy_u8Value){
     case ENABLE  : SET_BIT(Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8PinNum) ; break ;
     case DISABLE : CLR_BIT(Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8PinNum) ; break ;
     default      : CLR_BIT(Copy_u32GPIOPort + GPIO_DMACTL , Copy_u8PinNum) ; break ;
     }
}

/****************************************************************************************************/
/**                                Interrupt                                                        */
/****************************************************************************************************/
void MGPIO_voidEnableExtInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum){
	SET_BIT(Copy_u32GPIOPort + GPIO_IM , Copy_u8PinNum);
}

void MGPIO_voidDisableExtInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum){
	CLR_BIT(Copy_u32GPIOPort + GPIO_IM , Copy_u8PinNum); /* Mask the interrupt.*/
}

void MGPIO_voidInitInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum, u8 Copy_u8InterruptSense ){
  MGPIO_voidDisableExtInterrupt(Copy_u32GPIOPort, Copy_u8PinNum);
  switch(Copy_u8InterruptSense){
  case GPIO_INTERRUPT_LOW_LEVEL    : SET_BIT(Copy_u32GPIOPort + GPIO_IS  , Copy_u8PinNum);
                                     CLR_BIT(Copy_u32GPIOPort + GPIO_IBE , Copy_u8PinNum);
                                     CLR_BIT(Copy_u32GPIOPort + GPIO_IEV , Copy_u8PinNum); break ;
  case GPIO_INTERRUPT_HIGH_LEVEL   : SET_BIT(Copy_u32GPIOPort + GPIO_IS  , Copy_u8PinNum);
                                     CLR_BIT(Copy_u32GPIOPort + GPIO_IBE , Copy_u8PinNum);
                                     SET_BIT(Copy_u32GPIOPort + GPIO_IEV , Copy_u8PinNum); break ;
  case GPIO_INTERRUPT_FALLING_EDGE : CLR_BIT(Copy_u32GPIOPort + GPIO_IS  , Copy_u8PinNum);
                                     CLR_BIT(Copy_u32GPIOPort + GPIO_IBE , Copy_u8PinNum);
                                     CLR_BIT(Copy_u32GPIOPort + GPIO_IEV , Copy_u8PinNum); break ;
  case GPIO_INTERRUPT_RISING_EDGE  : CLR_BIT(Copy_u32GPIOPort + GPIO_IS  , Copy_u8PinNum);
                                     CLR_BIT(Copy_u32GPIOPort + GPIO_IBE , Copy_u8PinNum);
                                     SET_BIT(Copy_u32GPIOPort + GPIO_IEV , Copy_u8PinNum);
  case GPIO_INTERRUPT_BOTH_EDGES   : CLR_BIT(Copy_u32GPIOPort + GPIO_IS  , Copy_u8PinNum); break ;
  	  	  	  	  	  	  	  	  	 SET_BIT(Copy_u32GPIOPort + GPIO_IBE , Copy_u8PinNum);
  }
  MGPIO_voidClearInterrupt(Copy_u32GPIOPort , Copy_u8PinNum);
}

u8 MGPIO_voidGetPortRawInterruptStatus(u32 Copy_u32GPIOPort){
	return RD_REG(Copy_u32GPIOPort + GPIO_RIS);
}

u8 MGPIO_voidGetPinRawInterruptStatus(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum){
	return GET_BIT(Copy_u32GPIOPort + GPIO_RIS , Copy_u8PinNum);
}

u8 MGPIO_voidGetPortMaskInterruptStatus(u32 Copy_u32GPIOPort){
	return RD_REG(Copy_u32GPIOPort + GPIO_MIS);
}

u8 MGPIO_voidGetPinMaskInterruptStatus(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum){
	return GET_BIT(Copy_u32GPIOPort + GPIO_MIS , Copy_u8PinNum);
}

void MGPIO_voidClearInterrupt(u32 Copy_u32GPIOPort , u8 Copy_u8PinNum){
	SET_BIT(Copy_u32GPIOPort + GPIO_ICR , Copy_u8PinNum);
}

void

