#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSCTRL_interface.h"
#include "GPIO_interface.h"


void delay(unsigned long);
int main(void)
{
    MSYSCTRL_voidEnableClock(SYSCTRL_GPIO, SYSCTRL_GPIOF_ID);


    MGPIO_voidInitPin(GPIO_F_APB, 0, INPUT);
    MGPIO_voidInitPin(GPIO_F_APB, 4, INPUT);
    MGPIO_voidSelPinState(GPIO_F_APB, 0, GPIO_PIN_PULL_UP);
    MGPIO_voidSelPinState(GPIO_F_APB, 4, GPIO_PIN_PULL_UP);
    MGPIO_voidInitPin(GPIO_F_APB, 1, OUTPUT);
    MGPIO_voidInitPin(GPIO_F_APB, 2, OUTPUT);
    MGPIO_voidInitPin(GPIO_F_APB, 3, OUTPUT);
    MGPIO_voidEnablePin(GPIO_F_APB, 0);
    MGPIO_voidEnablePin(GPIO_F_APB, 1);
    MGPIO_voidEnablePin(GPIO_F_APB, 2);
    MGPIO_voidEnablePin(GPIO_F_APB, 3);
    MGPIO_voidEnablePin(GPIO_F_APB, 4);
    while (1)
    {
        if(!MGPIO_u8ReadPin(GPIO_F_APB, 0)){
        MGPIO_voidWritePin(GPIO_F_APB, 0, LOW);
        MGPIO_voidWritePin(GPIO_F_APB, 1, LOW);
        MGPIO_voidWritePin(GPIO_F_APB, 2, LOW);
        MGPIO_voidWritePin(GPIO_F_APB, 3, HIGH);
        delay(1000000);
        }else if(!MGPIO_u8ReadPin(GPIO_F_APB, 4)){
        MGPIO_voidWritePin(GPIO_F_APB, 0, LOW);
        MGPIO_voidWritePin(GPIO_F_APB, 1, HIGH);
        MGPIO_voidWritePin(GPIO_F_APB, 2, LOW);
        MGPIO_voidWritePin(GPIO_F_APB, 3, LOW);
        delay(1000000);
        }
    }
    //return 0;
}
void delay(unsigned long count)
{
    unsigned long i = 0;
    for (i = 0; i < count; i++)
        ;
}

