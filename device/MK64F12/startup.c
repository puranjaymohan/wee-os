#include <stdint.h>
#include <startup.h>
#include <MK64F12.h>

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
	(uint32_t)DMA0_IRQHandler,
	(uint32_t)DMA1_IRQHandler,
	(uint32_t)DMA2_IRQHandler,
	(uint32_t)DMA3_IRQHandler,
	(uint32_t)DMA4_IRQHandler,
	(uint32_t)DMA5_IRQHandler,
	(uint32_t)DMA6_IRQHandler,
	(uint32_t)DMA7_IRQHandler,
	(uint32_t)DMA8_IRQHandler,
	(uint32_t)DMA9_IRQHandler,
	(uint32_t)DMA10_IRQHandler,
	(uint32_t)DMA11_IRQHandler,
	(uint32_t)DMA12_IRQHandler,
	(uint32_t)DMA13_IRQHandler,
	(uint32_t)DMA14_IRQHandler,
	(uint32_t)DMA15_IRQHandler,
	(uint32_t)DMA_Error_IRQHandler,
	(uint32_t)MCM_IRQHandler,
	(uint32_t)FTFE_IRQHandler,
	(uint32_t)Read_Collision_IRQHandler,
	(uint32_t)LVD_LVW_IRQHandler,
	(uint32_t)LLW_IRQHandler,
	(uint32_t)Watchdog_IRQHandler,
	(uint32_t)RNG_IRQHandler,
	(uint32_t)I2C0_IRQHandler,
	(uint32_t)I2C1_IRQHandler,
	(uint32_t)SPI0_IRQHandler,
	(uint32_t)SPI1_IRQHandler,
	(uint32_t)I2S0_Tx_IRQHandler,
	(uint32_t)I2S0_Rx_IRQHandler,
	(uint32_t)UART0_LON_IRQHandler,
	(uint32_t)UART0_RX_TX_IRQHandler,
	(uint32_t)UART0_ERR_IRQHandler,
	(uint32_t)UART1_RX_TX_IRQHandler,
	(uint32_t)UART1_ERR_IRQHandler,
	(uint32_t)UART2_RX_TX_IRQHandler,
	(uint32_t)UART2_ERR_IRQHandler,
	(uint32_t)UART3_RX_TX_IRQHandler,
	(uint32_t)UART3_ERR_IRQHandler,
	(uint32_t)ADC0_IRQHandler,
	(uint32_t)CMP0_IRQHandler,
	(uint32_t)CMP1_IRQHandler,
	(uint32_t)FTM0_IRQHandler,
	(uint32_t)FTM1_IRQHandler,
	(uint32_t)FTM2_IRQHandler,
	(uint32_t)CMT_IRQHandler,
	(uint32_t)RTC_IRQHandler,
	(uint32_t)RTC_Seconds_IRQHandler,
	(uint32_t)PIT0_IRQHandler,
	(uint32_t)PIT1_IRQHandler,
	(uint32_t)PIT2_IRQHandler,
	(uint32_t)PIT3_IRQHandler,
	(uint32_t)PDB0_IRQHandler,
	(uint32_t)USB0_IRQHandler,
	(uint32_t)USBDCD_IRQHandler,
	(uint32_t)Reserved71_IRQHandler,
	(uint32_t)DAC0_IRQHandler,
	(uint32_t)MCG_IRQHandler,
	(uint32_t)LPTimer_IRQHandler,
	(uint32_t)PORTA_IRQHandler,
	(uint32_t)PORTB_IRQHandler,
	(uint32_t)PORTC_IRQHandler,
	(uint32_t)PORTD_IRQHandler,
	(uint32_t)PORTE_IRQHandler,
	(uint32_t)SWI_IRQHandler,
	(uint32_t)SPI2_IRQHandler,
	(uint32_t)UART4_RX_TX_IRQHandler,
	(uint32_t)UART4_ERR_IRQHandler,
	(uint32_t)UART5_RX_TX_IRQHandler,
	(uint32_t)UART5_ERR_IRQHandler,
	(uint32_t)CMP2_IRQHandler,
	(uint32_t)FTM3_IRQHandler,
	(uint32_t)DAC1_IRQHandler,
	(uint32_t)ADC1_IRQHandler,
	(uint32_t)I2C2_IRQHandler,
	(uint32_t)CAN0_ORed_Message_buffer_IRQHandler,
	(uint32_t)CAN0_Bus_Off_IRQHandler,
	(uint32_t)CAN0_Error_IRQHandler,
	(uint32_t)CAN0_Tx_Warning_IRQHandler,
	(uint32_t)CAN0_Rx_Warning_IRQHandler,
	(uint32_t)CAN0_Wake_Up_IRQHandler,
	(uint32_t)SDHC_IRQHandler,
	(uint32_t)ENET_1588_Timer_IRQHandler,
	(uint32_t)ENET_Transmit_IRQHandler,
	(uint32_t)ENET_Receive_IRQHandler,
	(uint32_t)ENET_Error_IRQHandler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler,
	(uint32_t)Default_Handler
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
