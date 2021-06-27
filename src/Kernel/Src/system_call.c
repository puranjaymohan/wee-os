#include <weeOs.h>
#include <sched.h>
#include <systemcall.h>

extern tcb *current_tcb;
extern char active_tasks[MAX_TASKS];
uint8_t c = 0;
void wee_os_system_call(uint32_t syscall_no __attribute__((unused)) , 
			task_prop *task_property __attribute__((unused)))
{
	 __asm__ volatile("svc 0");
}


void __attribute__((naked)) SVCall_Handler(void)
{	__disable_irq();
	uint32_t syscall_no = *(uint32_t *)__get_MSP();
	task_prop *task_property = (task_prop *)*((uint32_t *)__get_MSP() + 1);
	__asm__ volatile ("push {LR}");
	switch(syscall_no) {
	case 1: wee_os_syscall_yield();
		break;
	case 2: wee_os_syscall_kill();
		break;
	case 3:
		c = wee_os_add_thread(task_property);
		break;
	default:
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
	SysTick->VAL = 0;
	SCB->ICSR |= SCB_ICSR_PENDSTSET_Msk;
}


void wee_os_syscall_kill(void)
{
        if(current_tcb->next_tcb == current_tcb){
		__enable_irq();
		return;
	} else if(current_tcb->pid != 0) {
		(current_tcb-1)->next_tcb = current_tcb->next_tcb;
	} else {
		tcb *temp_tcb = current_tcb;
		while(temp_tcb->next_tcb != current_tcb)
			temp_tcb++;
		temp_tcb->next_tcb = current_tcb->next_tcb;
	}
	active_tasks[current_tcb->pid] = 0;
	__enable_irq();
	wee_os_syscall_yield();
}
