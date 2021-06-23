#ifndef __STARTUP__H
#define __STARTUP__H

void Default_Handler(void);
/* Interrupt Vector Handlers*/
void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Debug_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

void GPIOPortA_Handler(void) __attribute__((weak, alias("Default_Handler")));
void GPIOPortB_Handler(void) __attribute__((weak, alias("Default_Handler")));
void GPIOPortC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void GPIOPortD_Handler(void) __attribute__((weak, alias("Default_Handler")));
void GPIOPortE_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UART0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UART1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SSI0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PWMGenerator0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PWMGenerator1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PWMGenerator2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void ADC0Sequence0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void ADC0Sequence1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void ADC0Sequence2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void ADC0Sequence3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void WatchdogTimer0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Timer0A_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Timer0B_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Timer1A_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Timer1B_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Timer2A_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Timer2B_Handler(void) __attribute__((weak, alias("Default_Handler")));
void AnalogComparator0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SystemControl_Handler(void) __attribute__((weak, alias("Default_Handler")));
void FlashMemoryControl_Handler(void) __attribute__((weak, alias("Default_Handler")));
/* Interrupt Vector Handlers End*/

void init_data(uint32_t *dst_start, uint32_t *dst_end, uint32_t *src);
void init_bss(uint32_t *start, uint32_t *end);
#endif
