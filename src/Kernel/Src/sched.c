// SPDX-License-Identifier: MIT
#include <sched.h>

extern tcb * current_tcb;
static inline void scheduler(void) __attribute__((always_inline));
static inline void context_switch(void) __attribute__((always_inline));

#ifdef weighted_round_robin
static inline void schd_w_rr(void) __attribute__((always_inline));
#elif defined round_robin
static inline void schd_rr(void) __attribute__((always_inline));
#endif

void SysTick_Handler(void)
{
	__disable_irq();
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	__enable_irq();
}

void PendSV_Handler(void)
{
	__disable_irq();
	scheduler();
	__enable_irq();
}

inline void scheduler(void)
{
#ifdef weighted_round_robin
	schd_w_rr();
#elif defined round_robin
	schd_rr();
#endif
}

#ifdef weighted_round_robin
void schd_w_rr(void)
{
	if (current_tcb->c_weight != 0) {
		current_tcb->c_weight -= 1;
		__enable_irq();
		return;
	}
	context_switch();
	current_tcb->c_weight = current_tcb->weight;
	current_tcb = current_tcb->next_tcb;
	current_tcb->c_weight -= 1;
}
#elif defined round_robin
void schd_rr(void)
{
	context_switch();
	current_tcb = current_tcb->next_tcb;
}
#endif

inline void context_switch(void)
{
	__asm__ __volatile__ ("PUSH {R4-R11}");
	current_tcb->sp = (int32_t *)__get_MSP();
	__asm__ __volatile__ ("LDR SP, %0" ::"m"(current_tcb->next_tcb->sp));
	__asm__ __volatile__ ("POP {R4-R11}");
}
