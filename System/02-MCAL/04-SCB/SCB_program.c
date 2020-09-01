/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 31 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_reg.h"
#include "SYSCTRL_interface.h"
#include "SCB_config.h"
#include "SCB_private.h"

void MSCB_voidSetGroupPriority(){
	WR_REG(SCB_APINT , MNVIC_GROUP_SUB_DISTRIBUTION);
}


