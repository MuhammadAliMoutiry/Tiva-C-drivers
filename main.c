#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSCTRL_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "NVIC_interruptHandler.h"

void delay(unsigned long);

void fun1() {
	if (MGPIO_voidGetPinMaskInterruptStatus(GPIO_F_APB, 0)) {
		MGPIO_voidWritePin(GPIO_F_APB, 0, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 1, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 2, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 3, HIGH);
		delay(1000000);
		MGPIO_voidWritePin(GPIO_F_APB, 0, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 1, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 2, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 3, LOW);
		MGPIO_voidClearInterrupt(GPIO_F_APB, 0);
	} else if (MGPIO_voidGetPinMaskInterruptStatus(GPIO_F_APB, 4)) {
		MGPIO_voidWritePin(GPIO_F_APB, 0, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 1, HIGH);
		MGPIO_voidWritePin(GPIO_F_APB, 2, LOW);
		MGPIO_voidWritePin(GPIO_F_APB, 3, LOW);
		MGPIO_voidClearInterrupt(GPIO_F_APB, 4);
	}
}

int main(void) {
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

	MGPIO_voidInitInterrupt(GPIO_F_APB, 0, GPIO_INTERRUPT_BOTH_EDGES);
	MGPIO_voidEnableExtInterrupt(GPIO_F_APB, 0);
	MGPIO_voidInitInterrupt(GPIO_F_APB, 4, GPIO_INTERRUPT_LOW_LEVEL);
	MGPIO_voidEnableExtInterrupt(GPIO_F_APB, 4);
	SNVIC_voidInstallISRFunction(NVIC_GPIOF_IRQ, fun1);
	MNVIC_voidEnableInterrupt(NVIC_GPIO_F_ID);
	while (1) {
		/*
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
		 */
	}
	//return 0;
}
void delay(unsigned long count) {
	unsigned long i = 0;
	for (i = 0; i < count; i++)
		;
}

