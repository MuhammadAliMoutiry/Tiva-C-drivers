/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 21 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/
#ifndef GPIO_REG_H_
#define GPIO_REG_H_

#define GPIO_A_APB                                0x40004000
#define GPIO_A_AHB                                0x40058000
#define GPIO_B_APB                                0x40005000
#define GPIO_B_AHB                                0x40059000
#define GPIO_C_APB                                0x40006000
#define GPIO_C_AHB                                0x4005A000
#define GPIO_D_APB                                0x40007000
#define GPIO_D_AHB                                0x4005B000
#define GPIO_E_APB                                0x40024000
#define GPIO_E_AHB                                0x4005C000
#define GPIO_F_APB                                0x40025000
#define GPIO_F_AHB                                0x4005D000

#define GPIO_DATA_MASK                            0x3FC     /** This Mask Used To Unlock DATA reg */
#define GPIO_DATA                                 0x000
#define GPIO_DIR                                  0x400
#define GPIO_IS                                   0x404
#define GPIO_IBE                                  0x408
#define GPIO_IEV                                  0x40C
#define GPIO_IM                                   0x410
#define GPIO_RIS                                  0x414
#define GPIO_MIS                                  0x418
#define GPIO_ICR                                  0x41C
#define GPIO_AFSEL                                0x420
#define GPIO_DR2R                                 0x500
#define GPIO_DR4R                                 0x504
#define GPIO_DR8R                                 0x508
#define GPIO_ODR                                  0x50C
#define GPIO_PUR                                  0x510
#define GPIO_PDR                                  0x514
#define GPIO_SLR                                  0x518
#define GPIO_DEN                                  0x51C
#define GPIO_LOCK                                 0x520
#define GPIO_CR                                   0x524
#define GPIO_AMSEL                                0x528
#define GPIO_PCTL                                 0x52C
#define GPIO_ADCCTL                               0x530
#define GPIO_DMACTL                               0x534
#define GPIO_PeriphID4                            0xFD0
#define GPIO_PeriphID5                            0xFD4
#define GPIO_PeriphID6                            0xFD8
#define GPIO_PeriphID7                            0xFDC
#define GPIO_PeriphID0                            0xFE0
#define GPIO_PeriphID1                            0xFE4
#define GPIO_PeriphID2                            0xFE8
#define GPIO_PeriphID3                            0xFEC
#define GPIO_PCellID0                             0xFF0
#define GPIO_PCellID1                             0xFF4
#define GPIO_PCellID2                             0xFF8
#define GPIO_PCellID3                             0xFFC


#endif /* GPIO_REG_H_ */
