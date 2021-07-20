#include <stdint.h>
#include <startup.h>
#include <TM4C123.h>

extern uint32_t _estack;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _ldata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern int main(void);
extern void SystemInit(void);

const uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t)&_estack,
	(uint32_t)Reset_Handler,
	(uint32_t)NMI_Handler,
	(uint32_t)HardFault_Handler,
	(uint32_t)MemManage_Handler,
	(uint32_t)BusFault_Handler,
	(uint32_t)UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)SVCall_Handler,
	(uint32_t)Debug_Handler,
	0,
	(uint32_t)PendSV_Handler,
	(uint32_t)SysTick_Handler,
	(uint32_t)GPIOPortA_Handler,
	(uint32_t)GPIOPortB_Handler,
	(uint32_t)GPIOPortC_Handler,
	(uint32_t)GPIOPortD_Handler,
	(uint32_t)GPIOPortE_Handler,
	(uint32_t)UART0_Handler,
	(uint32_t)UART1_Handler,
	(uint32_t)SSI0_Handler,
	(uint32_t)I2C0_Handler,
	(uint32_t)PWM0Fault_Handler,
	(uint32_t)PWM0Generator0_Handler,
	(uint32_t)PWM0Generator1_Handler,
	(uint32_t)PWM0Generator2_Handler,
	(uint32_t)QEI0_Handler,
	(uint32_t)ADC0Sequence0_Handler,
	(uint32_t)ADC0Sequence1_Handler,
	(uint32_t)ADC0Sequence2_Handler,
	(uint32_t)ADC0Sequence3_Handler,
	(uint32_t)WatchdogTimer01_Handler,
	(uint32_t)Timer0A_16_32_Handler,
	(uint32_t)Timer0B_16_32_Handler,
	(uint32_t)Timer1A_16_32_Handler,
	(uint32_t)Timer1B_16_32_Handler,
	(uint32_t)Timer2A_16_32_Handler,
	(uint32_t)Timer2B_16_32_Handler,
	(uint32_t)AnalogComparator0_Handler,
	(uint32_t)AnalogComparator1_Handler,
	0,
	(uint32_t)SystemControl_Handler,
	(uint32_t)FlashMemoryControl_Handler,
	(uint32_t)GPIOPortF_Handler,
	0,
	0,
	(uint32_t)UART2_Handler,
	(uint32_t)SSI1_Handler,
	(uint32_t)Timer3A_16_32_Handler,
	(uint32_t)Timer3B_16_32_Handler,
	(uint32_t)I2C1_Handler,
	(uint32_t)QEI1_Handler,
	(uint32_t)CAN0_Handler,
	(uint32_t)CAN1_Handler,
	0,
	0,
	(uint32_t)HibernationModule_Handler,
	(uint32_t)USB_Handler,
	(uint32_t)PWM0Generator3_Handler,
	(uint32_t)DMASoftware_Handler,
	(uint32_t)DMAError_Handler,
	(uint32_t)ADC1Sequence0_Handler,
	(uint32_t)ADC1Sequence1_Handler,
	(uint32_t)ADC1Sequence2_Handler,
	(uint32_t)ADC1Sequence3_Handler,
	0,
	0,
	0,
	0,
	0,
	(uint32_t)SSI2_Handler,
	(uint32_t)SSI3_Handler,
	(uint32_t)UART3_Handler,
	(uint32_t)UART4_Handler,
	(uint32_t)UART5_Handler,
	(uint32_t)UART6_Handler,
	(uint32_t)UART7_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)I2C2_Handler,
	(uint32_t)I2C3_Handler,
	(uint32_t)Timer4A_16_32_Handler,
	(uint32_t)Timer4B_16_32_Handler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	(uint32_t)Timer5A_16_32_Handler,
	(uint32_t)Timer5B_16_32_Handler,
	(uint32_t)Timer0A_32_64_Handler,
	(uint32_t)Timer0B_32_64_Handler,
	(uint32_t)Timer1A_32_64_Handler,
	(uint32_t)Timer1B_32_64_Handler,
	(uint32_t)Timer2A_32_64_Handler,
	(uint32_t)Timer2B_32_64_Handler,
	(uint32_t)Timer3A_32_64_Handler,
	(uint32_t)Timer3B_32_64_Handler,
	(uint32_t)Timer4A_32_64_Handler,
	(uint32_t)Timer4B_32_64_Handler,
	(uint32_t)Timer5A_32_64_Handler,
	(uint32_t)Timer5B_32_64_Handler,
	(uint32_t)SystemException_Handler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	(uint32_t)PWM1Generator0_Handler,
	(uint32_t)PWM1Generator1_Handler,
	(uint32_t)PWM1Generator2_Handler,
	(uint32_t)PWM1Generator3_Handler,
	(uint32_t)PWM1Fault_Handler

};

void Reset_Handler(void)
{
	//SystemInit();
	init_data(&_sdata, &_edata, &_ldata);
	init_bss(&_sbss, &_ebss);
	SCB->CCR &= ~(SCB_CCR_STKALIGN_Msk);
	main();
}

void Default_Handler(void)
{
	while(1);
}

void init_data(uint32_t *dst_start, uint32_t *dst_end, uint32_t *src)
{
	while(dst_start < dst_end)
		*dst_start++ = *src++;
}

void init_bss(uint32_t *start, uint32_t *end)
{
	while(start < end)
		*start++ = 0;
}
