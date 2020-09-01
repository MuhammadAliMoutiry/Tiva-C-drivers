/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 31 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/


#ifndef NVIC_REG_H_
#define NVIC_REG_H_


#define NVIC_EN0                           ( 0x100 + 0xE000E000 )
#define NVIC_EN1                           ( 0x104 + 0xE000E000 )
#define NVIC_EN2                           ( 0x108 + 0xE000E000 )
#define NVIC_EN3                           ( 0x10C + 0xE000E000 )
#define NVIC_EN4                           ( 0x110 + 0xE000E000 )
#define NVIC_DIS0                          ( 0x180 + 0xE000E000 )
#define NVIC_DIS1                          ( 0x184 + 0xE000E000 )
#define NVIC_DIS2                          ( 0x188 + 0xE000E000 )
#define NVIC_DIS3                          ( 0x18C + 0xE000E000 )
#define NVIC_DIS4                          ( 0x190 + 0xE000E000 )
#define NVIC_PEND0                         ( 0x200 + 0xE000E000 )
#define NVIC_PEND1                         ( 0x204 + 0xE000E000 )
#define NVIC_PEND2                         ( 0x208 + 0xE000E000 )
#define NVIC_PEND3                         ( 0x20C + 0xE000E000 )
#define NVIC_PEND4                         ( 0x210 + 0xE000E000 )
#define NVIC_UNPEND0                       ( 0x280 + 0xE000E000 )
#define NVIC_UNPEND1                       ( 0x284 + 0xE000E000 )
#define NVIC_UNPEND2                       ( 0x288 + 0xE000E000 )
#define NVIC_UNPEND3                       ( 0x28C + 0xE000E000 )
#define NVIC_UNPEND4                       ( 0x290 + 0xE000E000 )
#define NVIC_ACTIVE0                       ( 0x300 + 0xE000E000 )
#define NVIC_ACTIVE1                       ( 0x304 + 0xE000E000 )
#define NVIC_ACTIVE2                       ( 0x308 + 0xE000E000 )
#define NVIC_ACTIVE3                       ( 0x30C + 0xE000E000 )
#define NVIC_ACTIVE4                       ( 0x310 + 0xE000E000 )
#define NVIC_PRI0                          ( 0x400 + 0xE000E000 )
#define NVIC_PRI1                          ( 0x404 + 0xE000E000 )
#define NVIC_PRI2                          ( 0x408 + 0xE000E000 )
#define NVIC_PRI3                          ( 0x40C + 0xE000E000 )
#define NVIC_PRI4                          ( 0x410 + 0xE000E000 )
#define NVIC_PRI5                          ( 0x414 + 0xE000E000 )
#define NVIC_PRI6                          ( 0x418 + 0xE000E000 )
#define NVIC_PRI7                          ( 0x41C + 0xE000E000 )
#define NVIC_PRI8                          ( 0x420 + 0xE000E000 )
#define NVIC_PRI9                          ( 0x424 + 0xE000E000 )
#define NVIC_PRI10                         ( 0x428 + 0xE000E000 )
#define NVIC_PRI11                         ( 0x42C + 0xE000E000 )
#define NVIC_PRI12                         ( 0x430 + 0xE000E000 )
#define NVIC_PRI13                         ( 0x434 + 0xE000E000 )
#define NVIC_PRI14                         ( 0x438 + 0xE000E000 )
#define NVIC_PRI15                         ( 0x43C + 0xE000E000 )
#define NVIC_PRI16                         ( 0x440 + 0xE000E000 )
#define NVIC_PRI17                         ( 0x444 + 0xE000E000 )
#define NVIC_PRI18                         ( 0x448 + 0xE000E000 )
#define NVIC_PRI19                         ( 0x44C + 0xE000E000 )
#define NVIC_PRI20                         ( 0x450 + 0xE000E000 )
#define NVIC_PRI21                         ( 0x454 + 0xE000E000 )
#define NVIC_PRI22                         ( 0x458 + 0xE000E000 )
#define NVIC_PRI23                         ( 0x45C + 0xE000E000 )
#define NVIC_PRI24                         ( 0x460 + 0xE000E000 )
#define NVIC_PRI25                         ( 0x464 + 0xE000E000 )
#define NVIC_PRI26                         ( 0x468 + 0xE000E000 )
#define NVIC_PRI27                         ( 0x46C + 0xE000E000 )
#define NVIC_PRI28                         ( 0x470 + 0xE000E000 )
#define NVIC_PRI29                         ( 0x474 + 0xE000E000 )
#define NVIC_PRI30                         ( 0x478 + 0xE000E000 )
#define NVIC_PRI31                         ( 0x47C + 0xE000E000 )
#define NVIC_PRI32                         ( 0x480 + 0xE000E000 )
#define NVIC_PRI33                         ( 0x484 + 0xE000E000 )
#define NVIC_PRI34                         ( 0x488 + 0xE000E000 )
#define NVIC_SWTRIG                        ( 0xF00 + 0xE000E000 )

#define NVIC_PRI                            ((volatile u8*)( 0x400 + 0xE000E000 )) //acess like array (pointer to array)


#endif /* NVIC_REG_H_ */
