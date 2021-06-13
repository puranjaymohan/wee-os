#include <stdint.h>
#include <startup.h>

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
	(uint32_t)WWDG_Handler,
	(uint32_t)PVD_PVM_Handler,
	(uint32_t)RTC_TAMP_STAMP_Handler,
	(uint32_t)RTC_WKUP_Handler,
	(uint32_t)FLASH_Handler,
	(uint32_t)RCC_Handler,
	(uint32_t)EXTI0_Handler,
	(uint32_t)EXTI1_Handler,
	(uint32_t)EXTI2_Handler,
	(uint32_t)EXTI3_Handler,
	(uint32_t)EXTI4_Handler,
	(uint32_t)DMA1_CH1_Handler,
	(uint32_t)DMA1_CH2_Handler,
	(uint32_t)DMA1_CH3_Handler,
	(uint32_t)DMA1_CH4_Handler,
	(uint32_t)DMA1_CH5_Handler,
	(uint32_t)DMA1_CH6_Handler,
	(uint32_t)DMA1_CH7_Handler,
	(uint32_t)ADC1_2_Handler,
	(uint32_t)CAN1_TX_Handler,
	(uint32_t)CAN1_RX0_Handler,
	(uint32_t)CAN1_RX1_Handler,
	(uint32_t)CAN1_SCE_Handler,
	(uint32_t)EXTI9_5_Handler,
	(uint32_t)TIM1_BRK_Handler,
	(uint32_t)TIM1_UP_Handler,
	(uint32_t)TIM1_TRG_COM_Handler,
	(uint32_t)TIM1_CC_Handler,
	(uint32_t)TIM2_Handler,
	(uint32_t)TIM3_Handler,
	(uint32_t)TIM4_Handler,
	(uint32_t)I2C1_EV_Handler,
	(uint32_t)I2C1_ER_Handler,
	(uint32_t)I2C2_EV_Handler,
	(uint32_t)I2C2_ER_Handler,
	(uint32_t)SPI1_Handler,
	(uint32_t)SPI2_Handler,
	(uint32_t)USART1_Handler,
	(uint32_t)USART2_Handler,
	(uint32_t)USART3_Handler,
	(uint32_t)EXTI15_10_Handler,
	(uint32_t)RTC_ALARM_Handler,
	(uint32_t)DFSDM1_FLT3_Handler,
	(uint32_t)TIM8_BRK_Handler,
	(uint32_t)TIM8_UP_Handler,
	(uint32_t)TIM8_TRG_COM_Handler,
	(uint32_t)TIM8_CC_Handler,
	(uint32_t)ADC3_Handler,
	(uint32_t)FMC_Handler,
	(uint32_t)SDMMC1_Handler,
	(uint32_t)TIM5_Handler,
	(uint32_t)SPI3_Handler,
	(uint32_t)UART4_Handler,
	(uint32_t)UART5_Handler,
	(uint32_t)TIM6_DACUNDER_Handler,
	(uint32_t)TIM7_Handler,
	(uint32_t)DMA2_CH1_Handler,
	(uint32_t)DMA2_CH2_Handler,
	(uint32_t)DMA2_CH3_Handler,
	(uint32_t)DMA2_CH4_Handler,
	(uint32_t)DMA2_CH5_Handler,
	(uint32_t)DFSDM1_FLT0_Handler,
	(uint32_t)DFSDM1_FLT1_Handler,
	(uint32_t)DFSDM1_FLT2_Handler,
	(uint32_t)COMP_Handler,
	(uint32_t)LPTIM1_Handler,
	(uint32_t)LPTIM2_Handler,
	(uint32_t)OTG_FS_Handler,
	(uint32_t)DMA2_CH6_Handler,
	(uint32_t)DMA2_CH7_Handler,
	(uint32_t)LPUART1_Handler,
	(uint32_t)QUADSPI_Handler,
	(uint32_t)I2C3_EV_Handler,
	(uint32_t)I2C3_ER_Handler,
	(uint32_t)SAI1_Handler,
	(uint32_t)SAI2_Handler,
	(uint32_t)SWPMI1_Handler,
	(uint32_t)TSC_Handler,
	(uint32_t)LCD_Handler,
	(uint32_t)AES_Handler,
	(uint32_t)RNG_Handler,
	(uint32_t)FPU_Handler
};

void Reset_Handler(void)
{
	SystemInit();
	init_data(&_sdata, &_edata, &_ldata);
	init_bss(&_sbss, &_ebss);
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
