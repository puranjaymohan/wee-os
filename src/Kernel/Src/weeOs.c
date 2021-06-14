#include <weeOs.h>

typedef struct tcb {
	int32_t *sp;
	struct tcb *next_tcb;
} tcb;

tcb *current_tcb;

tcb tcbs[NUM_TASKS];
int32_t STACK[NUM_TASKS][STACK_SIZE];

static void wee_os_stack_init(uint8_t i )
{
	tcbs[i].sp = &STACK[i][STACK_SIZE-16];
	STACK[i][xPSR] = (1 << 24);
}

uint8_t wee_os_addthreads(void(*task0)(void), void(*task1)(void),
			  void(*task2)(void))
{
	__disable_irq();

	tcbs[0].next_tcb = &tcbs[1];
	tcbs[1].next_tcb = &tcbs[2];
	tcbs[2].next_tcb = &tcbs[0];

	wee_os_stack_init(0);
	wee_os_stack_init(1);
	wee_os_stack_init(2);

	STACK[0][PC] = (int32_t)task0;
	STACK[1][PC] = (int32_t)task1;
	STACK[2][PC] = (int32_t)task2;

	current_tcb = &tcbs[0];

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
	__asm__ ("BX LR");
}


void wee_os_launch(uint32_t quanta_ms)
{
	__disable_irq();
	SysTick->CTRL = 0;
	SysTick->VAL = 0;
	NVIC_SetPriority (-1, 0);
	SysTick_Config(((quanta_ms*SystemCoreClock)/1000) - 1);
	wee_os_schd_launch();
}

void SysTick_Handler(void)
{
	__disable_irq();
	__asm__ __volatile__ ("PUSH {R4-R11}");
	__asm__ __volatile__ ("LDR SP, %0" ::"m"(current_tcb->next_tcb->sp));
	__asm__ __volatile__ ("POP {R4-R11}");
	current_tcb = current_tcb->next_tcb;
	__enable_irq();
}
