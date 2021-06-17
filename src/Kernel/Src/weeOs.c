#include <weeOs.h>
#include <sched.h>

tcb tcbs[MAX_TASKS];
tcb *task_ptr=&tcbs[0];
tcb *current_tcb = &tcbs[0];

int32_t STACK[MAX_TASKS][STACK_SIZE];

static void wee_os_stack_init(uint8_t i )
{
	tcbs[i].sp = &STACK[i][STACK_SIZE-16];
	STACK[i][xPSR] = (1 << 24);
}

uint8_t wee_os_addthread(void(*task)(void)
#ifdef weighted_round_robin
			,uint32_t weight
#endif
		)
{
	__disable_irq();
	uint32_t task_num = task_ptr - &tcbs[0];
	if (task_num>MAX_TASKS)
		return 0;

	if (task_ptr != &tcbs[0])
		(task_ptr-1)->next_tcb = task_ptr;

	task_ptr->next_tcb = &tcbs[0];
	task_ptr->pid = task_num;
#ifdef weighted_round_robin
	task_ptr->weight = weight;
	task_ptr->c_weight = weight;
#endif
	wee_os_stack_init(task_num);
	STACK[task_num][PC] = (int32_t)task;

	task_ptr++;

	__enable_irq();
	return 1;
}

static void wee_os_schd_launch()
{
	__asm__ ("LDR SP, %0"::"m"(current_tcb->sp));
	__asm__ ("POP {R4-R11}");
	__asm__ ("POP {R0-R3}");
	__asm__ ("POP {R12}");
	__asm__ ("ADD SP, SP, #4");
	__asm__ ("POP {LR}");
	__asm__ ("ADD SP, SP, #4");
	__enable_irq();
	__set_CONTROL(0x01);
	__asm__ ("BX LR");
}


void wee_os_launch(uint32_t quanta_ms)
{
	__disable_irq();
	SysTick->CTRL = 0;
	SysTick->VAL = 0;
	NVIC_SetPriority(-1, 0);
	NVIC_SetPriority(-2, 15);
	SysTick_Config(((quanta_ms*SystemCoreClock)/1000) - 1);
#ifdef weighted_round_robin
	current_tcb->c_weight -= 1;
#endif
	wee_os_schd_launch();
}
