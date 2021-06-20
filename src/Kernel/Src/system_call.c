#include <weeOs.h>
#include <sched.h>
#include <systemcall.h>

extern tcb *current_tcb;

uint32_t c=0;

void wee_os_system_call(uint32_t syscall_no __attribute__((unused)))
{
	 __asm__ volatile("svc 0");
}

void __attribute__((naked)) SVCall_Handler(void)
{	__disable_irq();
	uint32_t syscall_no = *(uint32_t *)__get_MSP();
	__asm__ volatile ("push {LR}");
	switch(syscall_no)
	{
		case 1: wee_os_syscall_yield();
			break;
		default: c++;
			break;
	}
	__enable_irq();
	__asm__ volatile ("pop {LR}");
	__asm__ volatile ("BX LR");
}

void wee_os_syscall_yield(void)
{
#ifdef weighted_round_robin
	current_tcb->c_weight = 0;
#endif
	SCB->ICSR |= SCB_ICSR_PENDSTSET_Msk;
}
