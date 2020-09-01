/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 20 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

/** Bit Operations */
#define SET_BIT(VAR,BIT)           (*(volatile u32*)(VAR)) |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)           (*(volatile u32*)(VAR)) &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)           (((*(volatile u32*)(VAR)) >> (BIT)) & 1)
#define TOG_BIT(VAR,BIT)           (*(volatile u32*)(VAR)) ^=  (1 << (BIT))

/** Register Operations */
#define WR_REG(REG,VAL)           ((*(volatile u32*)(REG)) = VAL )
#define RD_REG(REG)               (*(volatile u32*)(REG))
#define SET_REG(REG)              WR_REG(REG,0xFF)

#endif 
