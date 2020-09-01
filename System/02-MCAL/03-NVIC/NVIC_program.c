/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 31 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_reg.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptID) {
	if (Copy_u8InterruptID <= 31) {
		SET_BIT(NVIC_EN0, Copy_u8InterruptID);
	} else if (Copy_u8InterruptID <= 63) {
		SET_BIT(NVIC_EN1, Copy_u8InterruptID - 32);
	} else if (Copy_u8InterruptID <= 95) {
		SET_BIT(NVIC_EN2, Copy_u8InterruptID - 64);
	} else if (Copy_u8InterruptID <= 127) {
		SET_BIT(NVIC_EN3, Copy_u8InterruptID - 96);
	} else if (Copy_u8InterruptID <= 138) {
		SET_BIT(NVIC_EN4, Copy_u8InterruptID - 128);
	} else {

	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptID) {
	if (Copy_u8InterruptID <= 31) {
		SET_BIT(NVIC_DIS0, Copy_u8InterruptID);
	} else if (Copy_u8InterruptID <= 63) {
		SET_BIT(NVIC_DIS1, Copy_u8InterruptID - 32);
	} else if (Copy_u8InterruptID <= 95) {
		SET_BIT(NVIC_DIS2, Copy_u8InterruptID - 64);
	} else if (Copy_u8InterruptID <= 127) {
		SET_BIT(NVIC_DIS3, Copy_u8InterruptID - 96);
	} else if (Copy_u8InterruptID <= 138) {
		SET_BIT(NVIC_DIS4, Copy_u8InterruptID - 128);
	} else {

	}
}

void MNVIC_voidSetInterruptPendingFlag(u8 Copy_u8InterruptID) {
	if (Copy_u8InterruptID <= 31) {
		SET_BIT(NVIC_PEND0, Copy_u8InterruptID);
	} else if (Copy_u8InterruptID <= 63) {
		SET_BIT(NVIC_PEND1, Copy_u8InterruptID - 32);
	} else if (Copy_u8InterruptID <= 95) {
		SET_BIT(NVIC_PEND2, Copy_u8InterruptID - 64);
	} else if (Copy_u8InterruptID <= 127) {
		SET_BIT(NVIC_PEND3, Copy_u8InterruptID - 96);
	} else if (Copy_u8InterruptID <= 138) {
		SET_BIT(NVIC_PEND4, Copy_u8InterruptID - 128);
	} else {

	}
}

void MNVIC_voidClearInterruptPendingFlag(u8 Copy_u8InterruptID) {
	if (Copy_u8InterruptID <= 31) {
		SET_BIT(NVIC_UNPEND0, Copy_u8InterruptID);
	} else if (Copy_u8InterruptID <= 63) {
		SET_BIT(NVIC_UNPEND1, Copy_u8InterruptID - 32);
	} else if (Copy_u8InterruptID <= 95) {
		SET_BIT(NVIC_UNPEND2, Copy_u8InterruptID - 64);
	} else if (Copy_u8InterruptID <= 127) {
		SET_BIT(NVIC_UNPEND3, Copy_u8InterruptID - 96);
	} else if (Copy_u8InterruptID <= 138) {
		SET_BIT(NVIC_UNPEND4, Copy_u8InterruptID - 128);
	} else {

	}
}

u32 MNVIC_u32GetActiveFlag(u8 Copy_u8InterruptID){
	u8 Local_u8Result = 0;
	if (Copy_u8InterruptID <= 31) {
		Local_u8Result = GET_BIT(NVIC_ACTIVE0, Copy_u8InterruptID);
	} else if (Copy_u8InterruptID <= 63) {
		Local_u8Result = GET_BIT(NVIC_ACTIVE1, (Copy_u8InterruptID - 32));
	} else if (Copy_u8InterruptID <= 95) {
		Local_u8Result = GET_BIT(NVIC_ACTIVE2, (Copy_u8InterruptID - 64));
	} else if (Copy_u8InterruptID <= 127) {
		Local_u8Result = GET_BIT(NVIC_ACTIVE3, (Copy_u8InterruptID - 96));
	} else if (Copy_u8InterruptID <= 138) {
		Local_u8Result = GET_BIT(NVIC_ACTIVE4, (Copy_u8InterruptID - 128));
	} else {

	}
	return Local_u8Result;
}

void MNVIC_voidSetPriority(u8 Copy_u8InterruptID ,u8 Copy_u8Priority){
	NVIC_PRI[Copy_u8InterruptID] = (Copy_u8Priority << 5);
}

void MNVIC_voidTriggerSoftwareInterrupt(u8 Copy_u8InterruptID){
	WR_REG(NVIC_SWTRIG , Copy_u8InterruptID);
}


