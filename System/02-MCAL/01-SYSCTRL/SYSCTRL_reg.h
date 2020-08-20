/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 20 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#ifndef SYSCTRL_REG_H_
#define SYSCTRL_REG_H_

#define SYSCTRL_DID0                                    (*(volatile u32*)(0x400FE000 + 0x000))
#define SYSCTRL_DID1                                    (*(volatile u32*)(0x400FE000 + 0x004))
#define SYSCTRL_PBORCTL                                 (*(volatile u32*)(0x400FE000 + 0x030))
#define SYSCTRL_RIS                                     (*(volatile u32*)(0x400FE000 + 0x050))
#define SYSCTRL_IMC                                     (*(volatile u32*)(0x400FE000 + 0x054))
#define SYSCTRL_MISC                                    (*(volatile u32*)(0x400FE000 + 0x058))
#define SYSCTRL_RESC                                    (*(volatile u32*)(0x400FE000 + 0x05C))
#define SYSCTRL_RCC                                     (*(volatile u32*)(0x400FE000 + 0x060))
#define SYSCTRL_GPIOHBCTL                               (*(volatile u32*)(0x400FE000 + 0x06C))
#define SYSCTRL_RCC2                                    (*(volatile u32*)(0x400FE000 + 0x070))
#define SYSCTRL_MOSCCTL                                 (*(volatile u32*)(0x400FE000 + 0x07C))
#define SYSCTRL_DSLPCLKCFG                              (*(volatile u32*)(0x400FE000 + 0x144))
#define SYSCTRL_SYSPROP                                 (*(volatile u32*)(0x400FE000 + 0x14C))
#define SYSCTRL_PIOSCCAL                                (*(volatile u32*)(0x400FE000 + 0x150))
#define SYSCTRL_PIOSCSTAT                               (*(volatile u32*)(0x400FE000 + 0x154))
#define SYSCTRL_PLLFREQ0                                (*(volatile u32*)(0x400FE000 + 0x160))
#define SYSCTRL_PLLFREQ1                                (*(volatile u32*)(0x400FE000 + 0x164))
#define SYSCTRL_PLLSTAT                                 (*(volatile u32*)(0x400FE000 + 0x168))
#define SYSCTRL_SLPPWRCFG                               (*(volatile u32*)(0x400FE000 + 0x188))
#define SYSCTRL_DSLPPWRCFG                              (*(volatile u32*)(0x400FE000 + 0x18C))
#define SYSCTRL_LDOSPCTL                                (*(volatile u32*)(0x400FE000 + 0x1B4))
#define SYSCTRL_LDOSPCAL                                (*(volatile u32*)(0x400FE000 + 0x1B8))
#define SYSCTRL_LDODPCTL                                (*(volatile u32*)(0x400FE000 + 0x1BC))
#define SYSCTRL_LDODPCAL                                (*(volatile u32*)(0x400FE000 + 0x1C0))
#define SYSCTRL_SDPMST                                  (*(volatile u32*)(0x400FE000 + 0x1CC))
#define SYSCTRL_PPWD                                    (*(volatile u32*)(0x400FE000 + 0x300))
#define SYSCTRL_PPTIMER                                 (*(volatile u32*)(0x400FE000 + 0x304))
#define SYSCTRL_PPGPIO                                  (*(volatile u32*)(0x400FE000 + 0x308))
#define SYSCTRL_PPDMA                                   (*(volatile u32*)(0x400FE000 + 0x30C))
#define SYSCTRL_PPHIB                                   (*(volatile u32*)(0x400FE000 + 0x314))
#define SYSCTRL_PPUART                                  (*(volatile u32*)(0x400FE000 + 0x318))
#define SYSCTRL_PPSSI                                   (*(volatile u32*)(0x400FE000 + 0x31C))
#define SYSCTRL_PPI2C                                   (*(volatile u32*)(0x400FE000 + 0x320))
#define SYSCTRL_PPUSB                                   (*(volatile u32*)(0x400FE000 + 0x328))
#define SYSCTRL_PPCAN                                   (*(volatile u32*)(0x400FE000 + 0x334))
#define SYSCTRL_PPADC                                   (*(volatile u32*)(0x400FE000 + 0x338))
#define SYSCTRL_PPACMP                                  (*(volatile u32*)(0x400FE000 + 0x33C))
#define SYSCTRL_PPPWM                                   (*(volatile u32*)(0x400FE000 + 0x340))
#define SYSCTRL_PPQEI                                   (*(volatile u32*)(0x400FE000 + 0x344))
#define SYSCTRL_PPEEPROM                                (*(volatile u32*)(0x400FE000 + 0x358))
#define SYSCTRL_PPWTIMER                                (*(volatile u32*)(0x400FE000 + 0x35C))
#define SYSCTRL_SRWD                                    (*(volatile u32*)(0x400FE000 + 0x500))
#define SYSCTRL_SRTIMER                                 (*(volatile u32*)(0x400FE000 + 0x504))
#define SYSCTRL_SRGPIO                                  (*(volatile u32*)(0x400FE000 + 0x508))
#define SYSCTRL_SRDMA                                   (*(volatile u32*)(0x400FE000 + 0x50C))
#define SYSCTRL_SRHIB                                   (*(volatile u32*)(0x400FE000 + 0x514))
#define SYSCTRL_SRUART                                  (*(volatile u32*)(0x400FE000 + 0x518))
#define SYSCTRL_SRSSI                                   (*(volatile u32*)(0x400FE000 + 0x51C))
#define SYSCTRL_SRI2C                                   (*(volatile u32*)(0x400FE000 + 0x520))
#define SYSCTRL_SRUSB                                   (*(volatile u32*)(0x400FE000 + 0x528))
#define SYSCTRL_SRCAN                                   (*(volatile u32*)(0x400FE000 + 0x534))
#define SYSCTRL_SRADC                                   (*(volatile u32*)(0x400FE000 + 0x538))
#define SYSCTRL_SRACMP                                  (*(volatile u32*)(0x400FE000 + 0x53C))
#define SYSCTRL_SRPWM                                   (*(volatile u32*)(0x400FE000 + 0x540))
#define SYSCTRL_SRQEI                                   (*(volatile u32*)(0x400FE000 + 0x544))
#define SYSCTRL_SREEPROM                                (*(volatile u32*)(0x400FE000 + 0x558))
#define SYSCTRL_SRWTIMER                                (*(volatile u32*)(0x400FE000 + 0x55C))
#define SYSCTRL_RCGCWD                                  (*(volatile u32*)(0x400FE000 + 0x600))
#define SYSCTRL_RCGCTIMER                               (*(volatile u32*)(0x400FE000 + 0x604))
#define SYSCTRL_RCGCGPIO                                (*(volatile u32*)(0x400FE000 + 0x608))
#define SYSCTRL_RCGCDMA                                 (*(volatile u32*)(0x400FE000 + 0x60C))
#define SYSCTRL_RCGCHIB                                 (*(volatile u32*)(0x400FE000 + 0x614))
#define SYSCTRL_RCGCUART                                (*(volatile u32*)(0x400FE000 + 0x618))
#define SYSCTRL_RCGCSSI                                 (*(volatile u32*)(0x400FE000 + 0x61C))
#define SYSCTRL_RCGCI2C                                 (*(volatile u32*)(0x400FE000 + 0x620))
#define SYSCTRL_RCGCUSB                                 (*(volatile u32*)(0x400FE000 + 0x628))
#define SYSCTRL_RCGCCAN                                 (*(volatile u32*)(0x400FE000 + 0x634))
#define SYSCTRL_RCGCADC                                 (*(volatile u32*)(0x400FE000 + 0x638))
#define SYSCTRL_RCGCACMP                                (*(volatile u32*)(0x400FE000 + 0x63C))
#define SYSCTRL_RCGCPWM                                 (*(volatile u32*)(0x400FE000 + 0x640))
#define SYSCTRL_RCGCQEI                                 (*(volatile u32*)(0x400FE000 + 0x644))
#define SYSCTRL_RCGCEEPROM                              (*(volatile u32*)(0x400FE000 + 0x658))
#define SYSCTRL_RCGCWTIMER                              (*(volatile u32*)(0x400FE000 + 0x65C))
#define SYSCTRL_SCGCWD                                  (*(volatile u32*)(0x400FE000 + 0x700))
#define SYSCTRL_SCGCTIMER                               (*(volatile u32*)(0x400FE000 + 0x704))
#define SYSCTRL_SCGCGPIO                                (*(volatile u32*)(0x400FE000 + 0x708))
#define SYSCTRL_SCGCDMA                                 (*(volatile u32*)(0x400FE000 + 0x70C))
#define SYSCTRL_SCGCHIB                                 (*(volatile u32*)(0x400FE000 + 0x714))
#define SYSCTRL_SCGCUART                                (*(volatile u32*)(0x400FE000 + 0x718))
#define SYSCTRL_SCGCSSI                                 (*(volatile u32*)(0x400FE000 + 0x71C))
#define SYSCTRL_SCGCI2C                                 (*(volatile u32*)(0x400FE000 + 0x720))
#define SYSCTRL_SCGCUSB                                 (*(volatile u32*)(0x400FE000 + 0x728))
#define SYSCTRL_SCGCCAN                                 (*(volatile u32*)(0x400FE000 + 0x734))
#define SYSCTRL_SCGCADC                                 (*(volatile u32*)(0x400FE000 + 0x738))
#define SYSCTRL_SCGCACMP                                (*(volatile u32*)(0x400FE000 + 0x73C))
#define SYSCTRL_SCGCPWM                                 (*(volatile u32*)(0x400FE000 + 0x740))
#define SYSCTRL_SCGCQEI                                 (*(volatile u32*)(0x400FE000 + 0x744))
#define SYSCTRL_SCGCEEPROM                              (*(volatile u32*)(0x400FE000 + 0x758))
#define SYSCTRL_SCGCWTIMER                              (*(volatile u32*)(0x400FE000 + 0x75C))
#define SYSCTRL_DCGCWD                                  (*(volatile u32*)(0x400FE000 + 0x800))
#define SYSCTRL_DCGCTIMER                               (*(volatile u32*)(0x400FE000 + 0x804))
#define SYSCTRL_DCGCGPIO                                (*(volatile u32*)(0x400FE000 + 0x808))
#define SYSCTRL_DCGCDMA                                 (*(volatile u32*)(0x400FE000 + 0x80C))
#define SYSCTRL_DCGCHIB                                 (*(volatile u32*)(0x400FE000 + 0x814))
#define SYSCTRL_DCGCUART                                (*(volatile u32*)(0x400FE000 + 0x818))
#define SYSCTRL_DCGCSSI                                 (*(volatile u32*)(0x400FE000 + 0x81C))
#define SYSCTRL_DCGCI2C                                 (*(volatile u32*)(0x400FE000 + 0x820))
#define SYSCTRL_DCGCUSB                                 (*(volatile u32*)(0x400FE000 + 0x828))
#define SYSCTRL_DCGCCAN                                 (*(volatile u32*)(0x400FE000 + 0x834))
#define SYSCTRL_DCGCADC                                 (*(volatile u32*)(0x400FE000 + 0x838))
#define SYSCTRL_DCGCACMP                                (*(volatile u32*)(0x400FE000 + 0x83C))
#define SYSCTRL_DCGCPWM                                 (*(volatile u32*)(0x400FE000 + 0x840))
#define SYSCTRL_DCGCQEI                                 (*(volatile u32*)(0x400FE000 + 0x844))
#define SYSCTRL_DCGCEEPROM                              (*(volatile u32*)(0x400FE000 + 0x858))
#define SYSCTRL_DCGCWTIMER                              (*(volatile u32*)(0x400FE000 + 0x85C))
#define SYSCTRL_PRWD                                    (*(volatile u32*)(0x400FE000 + 0xA00))
#define SYSCTRL_PRTIMER                                 (*(volatile u32*)(0x400FE000 + 0xA04))
#define SYSCTRL_PRGPIO                                  (*(volatile u32*)(0x400FE000 + 0xA08))
#define SYSCTRL_PRDMA                                   (*(volatile u32*)(0x400FE000 + 0xA0C))
#define SYSCTRL_PRHIB                                   (*(volatile u32*)(0x400FE000 + 0xA14))
#define SYSCTRL_PRUART                                  (*(volatile u32*)(0x400FE000 + 0xA18))
#define SYSCTRL_PRSSI                                   (*(volatile u32*)(0x400FE000 + 0xA1C))
#define SYSCTRL_PRI2C                                   (*(volatile u32*)(0x400FE000 + 0xA20))
#define SYSCTRL_PRUSB                                   (*(volatile u32*)(0x400FE000 + 0xA28))
#define SYSCTRL_PRCAN                                   (*(volatile u32*)(0x400FE000 + 0xA34))
#define SYSCTRL_PRADC                                   (*(volatile u32*)(0x400FE000 + 0xA38))
#define SYSCTRL_PRACMP                                  (*(volatile u32*)(0x400FE000 + 0xA3C))
#define SYSCTRL_PRPWM                                   (*(volatile u32*)(0x400FE000 + 0xA40))
#define SYSCTRL_PRQEI                                   (*(volatile u32*)(0x400FE000 + 0xA44))
#define SYSCTRL_PREEPROM                                (*(volatile u32*)(0x400FE000 + 0xA58))
#define SYSCTRL_PRWTIMER                                (*(volatile u32*)(0x400FE000 + 0xA5C))
#define SYSCTRL_DC0                                     (*(volatile u32*)(0x400FE000 + 0x008))
#define SYSCTRL_DC1                                     (*(volatile u32*)(0x400FE000 + 0x010))
#define SYSCTRL_DC2                                     (*(volatile u32*)(0x400FE000 + 0x014))
#define SYSCTRL_DC3                                     (*(volatile u32*)(0x400FE000 + 0x018))
#define SYSCTRL_DC4                                     (*(volatile u32*)(0x400FE000 + 0x01C))
#define SYSCTRL_DC5                                     (*(volatile u32*)(0x400FE000 + 0x020))
#define SYSCTRL_DC6                                     (*(volatile u32*)(0x400FE000 + 0x024))
#define SYSCTRL_DC7                                     (*(volatile u32*)(0x400FE000 + 0x028))
#define SYSCTRL_DC8                                     (*(volatile u32*)(0x400FE000 + 0x02C))
#define SYSCTRL_SRCR0                                   (*(volatile u32*)(0x400FE000 + 0x040))
#define SYSCTRL_SRCR1                                   (*(volatile u32*)(0x400FE000 + 0x044))
#define SYSCTRL_SRCR2                                   (*(volatile u32*)(0x400FE000 + 0x048))
#define SYSCTRL_RCGC0                                   (*(volatile u32*)(0x400FE000 + 0x100))
#define SYSCTRL_RCGC1                                   (*(volatile u32*)(0x400FE000 + 0x104))
#define SYSCTRL_RCGC2                                   (*(volatile u32*)(0x400FE000 + 0x108))
#define SYSCTRL_SCGC0                                   (*(volatile u32*)(0x400FE000 + 0x110))
#define SYSCTRL_SCGC1                                   (*(volatile u32*)(0x400FE000 + 0x114))
#define SYSCTRL_SCGC2                                   (*(volatile u32*)(0x400FE000 + 0x118))
#define SYSCTRL_DCGC0                                   (*(volatile u32*)(0x400FE000 + 0x120))
#define SYSCTRL_DCGC1                                   (*(volatile u32*)(0x400FE000 + 0x124))
#define SYSCTRL_DCGC2                                   (*(volatile u32*)(0x400FE000 + 0x128))
#define SYSCTRL_DC9                                     (*(volatile u32*)(0x400FE000 + 0x190))
#define SYSCTRL_NVMSTAT                                 (*(volatile u32*)(0x400FE000 + 0x1A0))

#endif /* SYSCTRL_REG_H_ */
