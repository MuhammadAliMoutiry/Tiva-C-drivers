/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 20 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#ifndef SYSCTRL_INTERFACE_H_
#define SYSCTRL_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCTRL_reg.h"
#include "SYSCTRL_private.h"
#include "SYSCTRL_config.h"

void SYSCTRL_voidEnableClock(u8 Copy_u8Peripheral , u8 Copy_u8PerId);
void SYSCTRL_voidDisableClock(u8 Copy_u8Peripheral , u8 Copy_u8PerId);

#endif /* SYSCTRL_INTERFACE_H_ */
