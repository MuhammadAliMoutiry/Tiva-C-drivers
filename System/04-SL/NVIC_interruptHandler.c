/***************************************************************************************************/
/** Author    : Muhammad Ali Moutiry                                                               */
/** Date      : 31 August 2020                                                                     */
/** Version   : V01                                                                                */
/***************************************************************************************************/

#include "NVIC_interruptHandler.h"

void (* g_pfnVirualVectors[])(void) =
{
	IntVirDefaultFun,                      // GPIO Port A
	IntVirDefaultFun,                      // GPIO Port B
	IntVirDefaultFun,                      // GPIO Port C
    IntVirDefaultFun,                      // GPIO Port D
	IntVirDefaultFun,                      // GPIO Port E
	IntVirDefaultFun,                      // UART0 Rx and Tx
	IntVirDefaultFun,                      // UART1 Rx and Tx
	IntVirDefaultFun,                      // SSI0 Rx and Tx
	IntVirDefaultFun,                      // I2C0 Master and Slave
	IntVirDefaultFun,                      // PWM Fault
	IntVirDefaultFun,                      // PWM Generator 0
	IntVirDefaultFun,                      // PWM Generator 1
	IntVirDefaultFun,                      // PWM Generator 2
	IntVirDefaultFun,                      // Quadrature Encoder 0
	IntVirDefaultFun,                      // ADC Sequence 0
	IntVirDefaultFun,                      // ADC Sequence 1
	IntVirDefaultFun,                      // ADC Sequence 2
	IntVirDefaultFun,                      // ADC Sequence 3
	IntVirDefaultFun,                      // Watchdog timer
	IntVirDefaultFun,                      // Timer 0 subtimer A
	IntVirDefaultFun,                      // Timer 0 subtimer B
	IntVirDefaultFun,                      // Timer 1 subtimer A
	IntVirDefaultFun,                      // Timer 1 subtimer B
	IntVirDefaultFun,                      // Timer 2 subtimer A
	IntVirDefaultFun,                      // Timer 2 subtimer B
	IntVirDefaultFun,                      // Analog Comparator 0
	IntVirDefaultFun,                      // Analog Comparator 1
	IntVirDefaultFun,                      // Analog Comparator 2
	IntVirDefaultFun,                      // System Control (PLL, OSC, BO)
	IntVirDefaultFun,                      // FLASH Control
	IntVirDefaultFun,                      // GPIO Port F
	IntVirDefaultFun,                      // UART2 Rx and Tx
	IntVirDefaultFun,                      // SSI1 Rx and Tx
	IntVirDefaultFun,                      // Timer 3 subtimer A
	IntVirDefaultFun,                      // Timer 3 subtimer B
	IntVirDefaultFun,                      // I2C1 Master and Slave
	IntVirDefaultFun,                      // Quadrature Encoder 1
	IntVirDefaultFun,                      // CAN0
	IntVirDefaultFun,                      // CAN1
	IntVirDefaultFun,                      // Hibernate
	IntVirDefaultFun,                      // USB0
	IntVirDefaultFun,                      // PWM Generator 3
	IntVirDefaultFun,                      // uDMA Software Transfer
	IntVirDefaultFun,                      // uDMA Error
	IntVirDefaultFun,                      // ADC1 Sequence 0
	IntVirDefaultFun,                      // ADC1 Sequence 1
	IntVirDefaultFun,                      // ADC1 Sequence 2
	IntVirDefaultFun,                      // ADC1 Sequence 3
	IntVirDefaultFun,                      // SSI2 Rx and Tx
	IntVirDefaultFun,                      // SSI3 Rx and Tx
	IntVirDefaultFun,                      // UART3 Rx and Tx
	IntVirDefaultFun,                      // UART4 Rx and Tx
	IntVirDefaultFun,                      // UART5 Rx and Tx
	IntVirDefaultFun,                      // UART6 Rx and Tx
	IntVirDefaultFun,                      // UART7 Rx and Tx
	IntVirDefaultFun,                      // I2C2 Master and Slave
	IntVirDefaultFun,                      // I2C3 Master and Slave
	IntVirDefaultFun,                      // Timer 4 subtimer A
	IntVirDefaultFun,                      // Timer 4 subtimer B
	IntVirDefaultFun,                      // Timer 5 subtimer A
	IntVirDefaultFun,                      // Timer 5 subtimer B
	IntVirDefaultFun,                      // Wide Timer 0 subtimer A
	IntVirDefaultFun,                      // Wide Timer 0 subtimer B
	IntVirDefaultFun,                      // Wide Timer 1 subtimer A
	IntVirDefaultFun,                      // Wide Timer 1 subtimer B
	IntVirDefaultFun,                      // Wide Timer 2 subtimer A
	IntVirDefaultFun,                      // Wide Timer 2 subtimer B
	IntVirDefaultFun,                      // Wide Timer 3 subtimer A
	IntVirDefaultFun,                      // Wide Timer 3 subtimer B
	IntVirDefaultFun,                      // Wide Timer 4 subtimer A
	IntVirDefaultFun,                      // Wide Timer 4 subtimer B
	IntVirDefaultFun,                      // Wide Timer 5 subtimer A
	IntVirDefaultFun,                      // Wide Timer 5 subtimer B
	IntVirDefaultFun,                      // FPU
	IntVirDefaultFun,                      // I2C4 Master and Slave
	IntVirDefaultFun,                      // I2C5 Master and Slave
	IntVirDefaultFun,                      // Quadrature Encoder 2
	IntVirDefaultFun,                      // PWM 1 Generator 0
	IntVirDefaultFun,                      // PWM 1 Generator 1
	IntVirDefaultFun,                      // PWM 1 Generator 2
	IntVirDefaultFun,                      // PWM 1 Generator 3
	IntVirDefaultFun                       // PWM 1 Fault
};

void NVIC_voidInstallISRFunction(g_ISRVirIdx_t Copy_g_ISRVirIdx_tIdx , void(*isr)(void)){
g_pfnVirualVectors[idx] = isr ;
}

void NVIC_voidDeinstallISRFunction(g_ISRVirIdx_t Copy_g_ISRVirIdx_tIdx ){
g_pfnVirualVectors[idx] = IntVirDefaultFun ;
}

void IntVirDefaultFun(void){

}

void PortAISRHandler(void){
	g_pfnVirualVectors[NVIC_GPIOA_IRQ];
}

void PortBISRHandler(void){
	g_pfnVirualVectors[NVIC_GPIOB_IRQ];
}

void PortCISRHandler(void){
	g_pfnVirualVectors[NVIC_GPIOC_IRQ];
}

void PortDISRHandler(void){
	g_pfnVirualVectors[NVIC_GPIOD_IRQ];
}

void PortEISRHandler(void){
	g_pfnVirualVectors[NVIC_GPIOE_IRQ];
}

void PortFISRHandler(void){
	g_pfnVirualVectors[NVIC_GPIOF_IRQ];
}
