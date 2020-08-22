#include "STD_TYPES.h"
#include "SYSCTRL_interface.h"
#include "GPIO_interface.h"


void delay(unsigned long);
int main(void)
{
    SYSCTRL_voidEnableClock(SYSCTRL_GPIO, SYSCTRL_GPIOF_ID);


    GPIO_voidInitPin(GPIO_F_APB, 0, INPUT);
    GPIO_voidInitPin(GPIO_F_APB, 4, INPUT);
    GPIO_voidSelPinState(GPIO_F_APB, 0, GPIO_PIN_PULL_UP);
    GPIO_voidSelPinState(GPIO_F_APB, 4, GPIO_PIN_PULL_UP);
    GPIO_voidInitPin(GPIO_F_APB, 1, OUTPUT);
    GPIO_voidInitPin(GPIO_F_APB, 2, OUTPUT);
    GPIO_voidInitPin(GPIO_F_APB, 3, OUTPUT);
    GPIO_voidEnablePin(GPIO_F_APB, 0);
    GPIO_voidEnablePin(GPIO_F_APB, 1);
    GPIO_voidEnablePin(GPIO_F_APB, 2);
    GPIO_voidEnablePin(GPIO_F_APB, 3);
    GPIO_voidEnablePin(GPIO_F_APB, 4);
    while (1)
    {
        if(!GPIO_u8ReadPin(GPIO_F_APB, 0)){
        GPIO_voidWritePin(GPIO_F_APB, 0, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 1, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 2, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 3, HIGH);
        delay(1000000);
        }else if(!GPIO_u8ReadPin(GPIO_F_APB, 4)){
        GPIO_voidWritePin(GPIO_F_APB, 0, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 1, HIGH);
        GPIO_voidWritePin(GPIO_F_APB, 2, LOW);
        GPIO_voidWritePin(GPIO_F_APB, 3, LOW);
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

