#include "STD_TYPES.h"
#include "SYSCTRL_interface.h"
#include "GPIO_interface.h"

//---SYSTEM CONTROL REGISTERS---//
#define SYS_CTRL_RCGC2  (*((volatile unsigned long *)0x400FE108))   //offset of RCGC2 register is 0x108
#define CLK_GPIOF   0x20
//---GPIO-F REGISTER---//
#define PORTF_DATA  (*((volatile unsigned long *)0x40025038))   //offset of DATA register for PF1, PF2, PF3 is 0x38 [PF7:PF0::9:2]
#define PORTF_DIR   (*((volatile unsigned long *)0x40025400))   //offset of DIR register is 0x400
#define PORTF_DEN   (*((volatile unsigned long *)0x4002551C))   //offset of DEN register is 0x51C
//---PORT-F I/O---//
#define PF1 0x02
#define PF2 0x04
#define PF3 0x08
//---FUNCTION PROTOTYPE---//
void delay(unsigned long);
int main(void)
{
    SYSCTRL_voidEnableClock(SYSCTRL_GPIO, SYSCTRL_GPIOF_ID);
    GPIO_voidInitPin(GPIO_F_APB, 0, OUTPUT);
    GPIO_voidInitPin(GPIO_F_APB, 1, OUTPUT);
    GPIO_voidInitPin(GPIO_F_APB, 2, OUTPUT);
    GPIO_voidInitPin(GPIO_F_APB, 3, OUTPUT);
    GPIO_voidEnablePin(GPIO_F_APB, 0);
    GPIO_voidEnablePin(GPIO_F_APB, 1);
    GPIO_voidEnablePin(GPIO_F_APB, 2);
    GPIO_voidEnablePin(GPIO_F_APB, 3);
    while (1)
    {
        GPIO_voidWritePin(GPIO_F_APB, 0, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 1, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 2, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 3, HIGH);
        delay(1000000);
        GPIO_voidWritePin(GPIO_F_APB, 0, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 1, HIGH);
        GPIO_voidWritePin(GPIO_F_APB, 2, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 3, LOW);
        delay(1000000);

    }
    //return 0;
}
void delay(unsigned long count)
{
    unsigned long i = 0;
    for (i = 0; i < count; i++)
        ;
}

