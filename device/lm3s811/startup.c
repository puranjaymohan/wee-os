#include <stdint.h>
#include <startup.h>
#include <lm3s811.h>

extern uint32_t _estack;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _ldata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern int main(void);
extern void SystemInit(void);

const uint32_t __VECTOR_TABLE[] __attribute__((section(".vectors"))) = {
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
	0,
	(uint32_t)PWMGenerator0_Handler,
	(uint32_t)PWMGenerator1_Handler,
	(uint32_t)PWMGenerator2_Handler,
	0,
	(uint32_t)ADC0Sequence0_Handler,
	(uint32_t)ADC0Sequence1_Handler,
	(uint32_t)ADC0Sequence2_Handler,
	(uint32_t)ADC0Sequence3_Handler,
	(uint32_t)WatchdogTimer0_Handler,
	(uint32_t)Timer0A_Handler,
	(uint32_t)Timer0B_Handler,
	(uint32_t)Timer1A_Handler,
	(uint32_t)Timer1B_Handler,
	(uint32_t)Timer2A_Handler,
	(uint32_t)Timer2B_Handler,
	(uint32_t)AnalogComparator0_Handler,
	0,
	0,
	(uint32_t)SystemControl_Handler,
	(uint32_t)FlashMemoryControl_Handler,
};

void Reset_Handler(void)
{
	SystemInit();
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
