/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 31 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#ifndef SSCB_REG_H_
#define SCB_REG_H_

#define SCB_ACTLR                (0xE000E000 + 0x008)
#define SCB_CPUID                (0xE000E000 + 0xD00)
#define SCB_INTCTRL              (0xE000E000 + 0xD04)
#define SCB_VTABLE               (0xE000E000 + 0xD08)
#define SCB_APINT                (0xE000E000 + 0xD0C)
#define SCB_SYSCTRL              (0xE000E000 + 0xD10)
#define SCB_CFGCTRL              (0xE000E000 + 0xD14)
#define SCB_SYSPRI1              (0xE000E000 + 0xD18)
#define SCB_SYSPRI2              (0xE000E000 + 0xD1C)
#define SCB_SYSPRI3              (0xE000E000 + 0xD20)
#define SCB_SYSHNDCTRL           (0xE000E000 + 0xD24)
#define SCB_FAULTSTAT            (0xE000E000 + 0xD28)
#define SCB_HFAULTSTAT           (0xE000E000 + 0xD2C)
#define SCB_MMADDR               (0xE000E000 + 0xD34)
#define SCB_FAULTADDR            (0xE000E000 + 0xD38)

#endif /* SCB_REG_H_ */
