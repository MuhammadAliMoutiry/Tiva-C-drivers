/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 20 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#include "SYSCTRL_interface.h"


void MSYSCTRL_voidInitSysClock(void){

}

void MSYSCTRL_voidEnableClock(u8 Copy_u8Peripheral , u8 Copy_u8PerId){
    switch(Copy_u8Peripheral){
    case SYSCTRL_GPIO : SET_BIT(SYSCTRL_RCGCGPIO ,Copy_u8PerId) ; break ;
    }
}

void MSYSCTRL_voidDisableClock(u8 Copy_u8Peripheral , u8 Copy_u8PerId){
    switch(Copy_u8Peripheral){
    case SYSCTRL_GPIO : CLR_BIT(SYSCTRL_RCGCGPIO ,Copy_u8PerId) ; break ;
    }
}



